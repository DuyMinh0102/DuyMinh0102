import urllib.request
import json
import re
import urllib.parse
import os

# --- CONFIGURATION ---
GITHUB_USERNAME = "DuyMinh0102"
PROBLEMS_REPO = "DuyMinh0102" 
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
                if "Source:" in clean_line:
                    metadata["Source"] = clean_line.split("Source:")[-1].strip()
                if "Status:" in clean_line:
                    metadata["Status"] = clean_line.split("Status:")[-1].strip()
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
                        note_lines.append(clean_line.replace('|', 'I').lstrip('* '))
            if note_lines:
                metadata["Note"] = "<br>".join(note_lines)
        return metadata
    except Exception:
        return metadata

def get_status_badge(status_raw):
    status = status_raw.upper().strip()
    # Replace spaces with %20 for URL safety in badge
    label = urllib.parse.quote(status)
    
    # SOLVED / ACCEPTED: Solid Green, Black Bold Text
    if any(x in status for x in ["SOLVED", "ACCEPTED", "AC"]):
        return f"![{status}](https://img.shields.io/badge/-{label}-00FF00?style=for-the-badge&labelColor=00FF00&logoColor=black)"
    
    # UNSOLVED / FAILED: Solid Red, Black Bold Text
    if any(x in status for x in ["UNSOLVED", "FAILED", "WA"]):
        return f"![{status}](https://img.shields.io/badge/-{label}-FF0000?style=for-the-badge&labelColor=FF0000&logoColor=black)"
    
    # PERCENTAGE: Whiter shade of Green (LightGreen)
    if "%" in status:
        return f"![{status}](https://img.shields.io/badge/-{label}-90EE90?style=for-the-badge&labelColor=90EE90&logoColor=black)"

    # FALLBACK: Light Grey
    return f"![{status}](https://img.shields.io/badge/-{label}-D3D3D3?style=for-the-badge&labelColor=D3D3D3&logoColor=black)"

def generate_markdown_table(tree):
    # Order: Folder | Status | Notes | Source & Problem
    table_lines = [
        "| Folder | Status | Notes | Source & Problem |",
        "| :--- | :---: | :---: | :--- |"
    ]
    found_files = False
    
    for item in tree:
        path = item['path']
        if item['type'] == 'blob' and any(path.startswith(f + "/") for f in TARGET_FOLDERS):
            if not path.lower().endswith('.cpp'):
                continue
            
            found_files = True
            parts = path.split('/')
            
            # Folder name fully capitalized
            folder_display = parts[-2].upper() if len(parts) > 1 else "ROOT"
            
            # Clean name: remove .cpp, replace _ with space, UPPERCASE
            raw_name = os.path.splitext(parts[-1])[0]
            clean_name = raw_name.replace('_', ' ').upper()
            
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            meta = fetch_file_metadata(path)
            
            # Status badge logic
            status_badge = get_status_badge(meta['Status'])
            
            # Notes toggle with 📝 icon
            note_content = meta['Note']
            if note_content and note_content != "-":
                notes_cell = f"<details><summary>📝 View</summary><br>{note_content}</details>"
            else:
                notes_cell = "-"

            # Source & Problem column (Last)
            source_cell = f"**[`{clean_name}`]({file_url})**<br>_{meta['Source']}_"
            
            table_lines.append(f"| `{folder_display}` | {status_badge} | {notes_cell} | {source_cell} |")
            
    return "\n".join(table_lines) if found_files else "*No problems found.*"

def update_readme(markdown_content):
    try:
        with open("README.md", "r", encoding="utf-8") as f:
            readme_text = f.read()

        if START_MARKER not in readme_text or END_MARKER not in readme_text:
            print(f"Error: Could not find markers in README.md")
            return

        pattern = rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}"
        replacement = f"{START_MARKER}\n\n{markdown_content}\n\n{END_MARKER}"
        
        new_readme = re.sub(pattern, replacement, readme_text, flags=re.DOTALL)

        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_readme)
        print("README.md has been beautified and updated.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    print("🚀 Syncing Competitive Programming portfolio...")
    repo_tree = get_repo_tree()
    if repo_tree:
        table = generate_markdown_table(repo_tree)
        update_readme(table)
