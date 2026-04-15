import urllib.request
import json
import re

# --- CONFIGURATION ---
GITHUB_USERNAME = "DuyMinh0102"
PROBLEMS_REPO = "Competitive_Programming"
BRANCH = "main"

# The script will only look for code files inside these folders
TARGET_FOLDERS = ["Learn", "PTNK", "Train"]
# ---------------------

def get_repo_tree():
    """Fetches the entire repository structure in one API call."""
    url = f"https://api.github.com/repos/{GITHUB_USERNAME}/{PROBLEMS_REPO}/git/trees/{BRANCH}?recursive=1"
    try:
        req = urllib.request.Request(url)
        with urllib.request.urlopen(req) as response:
            return json.loads(response.read().decode())['tree']
    except Exception as e:
        print(f"Error fetching repo tree: {e}")
        return []

def fetch_file_metadata(file_path):
    raw_url = f"https://raw.githubusercontent.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/{BRANCH}/{urllib.parse.quote(file_path)}"
    
    metadata = {"Source": "-", "Status": "-", "Note": "-"}
    try:
        req = urllib.request.Request(raw_url)
        with urllib.request.urlopen(req) as response:
            lines = response.read().decode('utf-8', errors='ignore').splitlines()
            
            is_capturing_note = False
            note_lines = []

            for line in lines[:50]: # Increased limit to 50 to capture the whole block
                clean_line = line.strip()
                
                # Capture Source and Status
                if "Source:" in clean_line:
                    metadata["Source"] = clean_line.split("Source:")[-1].strip()
                if "Status:" in clean_line:
                    metadata["Status"] = clean_line.split("Status:")[-1].strip()
                
                # Handle Multi-line Note
                if "Note:" in clean_line:
                    is_capturing_note = True
                    # Take the text after "Note:" on the same line
                    content = clean_line.split("Note:")[-1].strip()
                    if content: note_lines.append(content)
                    continue
                
                if is_capturing_note:
                    # Stop if we hit the end of the comment block or a signature
                    if "*/" in clean_line or "Author:" in clean_line:
                        is_capturing_note = False
                        break
                    # Append the line if it's not empty
                    if clean_line:
                        note_lines.append(clean_line)

            if note_lines:
                # Use <br> to create line breaks inside a Markdown table cell
                metadata["Note"] = "<br>".join(note_lines)
                    
        return metadata
    except Exception as e:
        print(f"Failed to fetch {file_path}: {e}")
        return metadata

def generate_markdown_table(tree):
    """Generates a Markdown table containing the problem details."""
    # Table header
    markdown = "| Problem / File | Folder | Source | Status | Notes |\n"
    markdown += "| --- | --- | --- | --- | --- |\n"
    
    found_files = False
    
    for item in tree:
        # Only process files (blobs) inside our target folders
        if item['type'] == 'blob' and any(item['path'].startswith(folder + "/") for folder in TARGET_FOLDERS):
            found_files = True
            file_path = item['path']
            file_name = file_path.split('/')[-1]
            folder_name = file_path.split('/')[0]
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(file_path)}"
            
            # Fetch the metadata from the file's comments
            print(f"Scanning {file_path}...")
            meta = fetch_file_metadata(file_path)
            
            # Add a row to the table
            markdown += f"| [{file_name}]({file_url}) | `{folder_name}` | {meta['Source']} | {meta['Status']} | {meta['Note']} |\n"
            
    if not found_files:
        return "*No problems found in the specified folders.*"
        
    return markdown

def update_readme(markdown_content):
    with open("README.md", "r", encoding="utf-8") as f:
        readme = f.read()

    # Fixed Regex: specifically looks for your HTML comment markers
    pattern = r"(\n)(.*?)(\n)"
    replacement = f"\\g<1>{markdown_content}\\g<3>"
    
    new_readme = re.sub(pattern, replacement, readme, flags=re.DOTALL)

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(new_readme)
