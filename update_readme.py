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
    """Fetches the raw file and extracts the Source, Status, and Note from comments."""
    # Use raw.githubusercontent to avoid standard API rate limits for file content
    raw_url = f"https://raw.githubusercontent.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/{BRANCH}/{urllib.parse.quote(file_path)}"
    
    metadata = {"Source": "-", "Status": "-", "Note": "-"}
    try:
        req = urllib.request.Request(raw_url)
        with urllib.request.urlopen(req) as response:
            # Read only the first 15 lines to save time/memory
            for _ in range(15):
                line = response.readline().decode('utf-8', errors='ignore').strip()
                if not line:
                    continue
                
                # Extract metadata if the keywords exist in the line
                if "Source:" in line:
                    metadata["Source"] = line.split("Source:")[-1].strip()
                if "Status:" in line:
                    metadata["Status"] = line.split("Status:")[-1].strip()
                if "Note:" in line:
                    metadata["Note"] = line.split("Note:")[-1].strip()
                    
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

    pattern = r"(\n)(.*?)(\n)"
    replacement = f"\\g<1>{markdown_content}\\g<3>"
    
    new_readme = re.sub(pattern, replacement, readme, flags=re.DOTALL)

    with open("README.md", "w", encoding="utf-8") as f:
        f.write(new_readme)

if __name__ == "__main__":
    print("Fetching repository tree...")
    tree = get_repo_tree()
    
    if tree:
        print("Generating markdown table...")
        markdown_table = generate_markdown_table(tree)
        
        print("Updating README.md...")
        update_readme(markdown_table)
        print("Done!")
    else:
        print("Could not retrieve repository data.")
