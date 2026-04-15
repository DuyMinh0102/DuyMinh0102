import urllib.request
import json
import re
import urllib.parse
import os

# --- CONFIGURATION ---
GITHUB_USERNAME = "DuyMinh0102"
PROBLEMS_REPO = "DuyMinh0102"  # Your profile repo
BRANCH = "main"
TARGET_FOLDERS = [
    "Competitive_Programming/Learn", 
    "Competitive_Programming/PTNK", 
    "Competitive_Programming/Train"
]
START_MARKER = "[//]: # (START_TABLE)"
END_MARKER = "[//]: # (END_TABLE)"
# ---------------------

def get_repo_tree():
    url = f"https://api.github.com/repos/{GITHUB_USERNAME}/{PROBLEMS_REPO}/git/trees/{BRANCH}?recursive=1"
    try:
        req = urllib.request.Request(url)
        # If running in GitHub Actions, this env var is automatically available if you pass it in YAML
        token = os.getenv("GITHUB_TOKEN")
        if token:
            req.add_header("Authorization", f"token {token}")
            
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
            for line in lines[:50]:
                clean_line = line.strip()
                # Parse Source
                if "Source:" in clean_line:
                    metadata["Source"] = clean_line.split("Source:")[-1].strip()
                # Parse Status
                if "Status:" in clean_line:
                    metadata["Status"] = clean_line.split("Status:")[-1].strip()
                # Parse Note block
                if "Note:" in clean_line:
                    is_capturing_note = True
                    content = clean_line.split("Note:")[-1].strip()
                    if content: note_lines.append(content)
                    continue
                if is_capturing_note:
                    if "*/" in clean_line or "Author:" in clean_line or "Time:" in clean_line:
                        is_capturing_note = False
                        break
                    if clean_line:
                        # Replace pipe to avoid breaking markdown table
                        note_lines.append(clean_line.replace('|', 'I').lstrip('* '))
            
            if note_lines:
                metadata["Note"] = "<br>".join(note_lines)
        return metadata
    except Exception:
        return metadata

def generate_markdown_table(tree):
    # Column 1 (Problem) removed as requested
    table_lines = [
        "| Folder | Source & Problem | Status | Notes |",
        "| :--- | :--- | :--- | :--- |"
    ]
    found_files = False
    
    # Sort tree by path so the table is alphabetical
    for item in tree:
        path = item['path']
        
        # Check if file is in target folders and is a .cpp file
        if item['type'] == 'blob' and any(path.startswith(f + "/") for f in TARGET_FOLDERS):
            if not path.lower().endswith('.cpp'):
                continue
            
            found_files = True
            parts = path.split('/')
            
            # 1. Folder Name Fully Capitalized (e.g., TRAIN)
            # parts[-2] gets the immediate parent folder
            raw_folder = parts[-2] if len(parts) > 1 else "ROOT"
            folder_display = raw_folder.upper()
            
            # 2. File Name without extension
            file_name_with_ext = parts[-1]
            display_name = os.path.splitext(file_name_with_ext)[0]
            
            # 3. Create Github Link
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            
            print(f"Processing: {display_name} in {folder_display}")
            meta = fetch_file_metadata(path)
            
            # 4. Notes with Toggle Button (<details>)
            note_raw = meta['Note']
            if note_raw and note_raw != "-":
                formatted_note = f"<details><summary>📁 View</summary><br>{note_raw}</details>"
            else:
                formatted_note = "-"

            # 5. Combined Problem Name and Source
            source_cell = f"**[{display_name}]({file_url})**<br>_{meta['Source']}_"
            
            table_lines.append(f"| `{folder_display}` | {source_cell} | {meta['Status']} | {formatted_note} |")
            
    return "\n".join(table_lines) if found_files else "*No .cpp problems found.*"

def update_readme(markdown_content):
    try:
        with open("README.md", "r", encoding="utf-8") as f:
            readme_text = f.read()

        if START_MARKER not in readme_text or END_MARKER not in readme_text:
            print(f"Error: Could not find markers in README.md")
            return

        # Pattern matches everything between the markers
        pattern = rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}"
        replacement = f"{START_MARKER}\n\n{markdown_content}\n\n{END_MARKER}"
        
        new_readme = re.sub(pattern, replacement, readme_text, flags=re.DOTALL)

        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_readme)
        print("README.md updated successfully.")
    except Exception as e:
        print(f"Error updating README: {e}")

if __name__ == "__main__":
    print("🚀 Starting Sync...")
    tree = get_repo_tree()
    if tree:
        table = generate_markdown_table(tree)
        update_readme(table)
    else:
        print("Failed to fetch repository data.")
