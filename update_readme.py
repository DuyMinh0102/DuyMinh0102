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

def get_repo_tree():
    url = f"https://api.github.com/repos/{GITHUB_USERNAME}/{PROBLEMS_REPO}/git/trees/{BRANCH}?recursive=1"
    try:
        req = urllib.request.Request(url)
        token = os.getenv("GITHUB_TOKEN")
        if token: req.add_header("Authorization", f"token {token}")
        with urllib.request.urlopen(req) as response:
            return json.loads(response.read().decode())['tree']
    except Exception as e:
        print(f"Error: {e}")
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
                    if "*/" in clean_line or "Author:" in clean_line:
                        is_capturing_note = False
                        break
                    if clean_line: note_lines.append(clean_line.replace('|', 'I').lstrip('* '))
            if note_lines: metadata["Note"] = "<br>".join(note_lines)
        return metadata
    except Exception: return metadata

def generate_markdown_table(tree):
    # Rearranged Headers: Folder | Status | Notes | Source & Problem
    table_lines = [
        "| Folder | Status | Notes | Source & Problem |",
        "| :--- | :---: | :---: | :--- |"
    ]
    found_files = False
    
    for item in tree:
        path = item['path']
        if item['type'] == 'blob' and any(path.startswith(f + "/") for f in TARGET_FOLDERS):
            if not path.lower().endswith('.cpp'): continue
            found_files = True
            
            parts = path.split('/')
            folder_display = parts[-2].upper()
            
            # 1. Clean filename: Remove extension, replace _ with space, UPPERCASE
            raw_name = os.path.splitext(parts[-1])[0]
            clean_name = raw_name.replace('_', ' ').upper()
            
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            meta = fetch_file_metadata(path)
            
            # 2. Status Badge (Colors)
            status_raw = meta['Status'].upper()
            if "SOLVED" in status_raw or "ACCEPTED" in status_raw or "AC" in status_raw:
                status_badge = f"![](https://img.shields.io/badge/-{status_raw}-brightgreen?style=flat-square)"
            elif "PROCESS" in status_raw or "TRYING" in status_raw:
                status_badge = f"![](https://img.shields.io/badge/-{status_raw}-orange?style=flat-square)"
            else:
                status_badge = f"![](https://img.shields.io/badge/-{status_raw}-lightgrey?style=flat-square)"
            
            # 3. Updated Notes Icon (📝)
            note_raw = meta['Note']
            if note_raw and note_raw != "-":
                notes_cell = f"<details><summary>📝 View</summary><br>{note_raw}</details>"
            else:
                notes_cell = "-"

            # 4. Source & Problem as Last Column
            # Note: GitHub doesn't support changing text color to white easily, 
            # so we use code tags ` ` to make the text pop against the background.
            source_cell = f"**[`{clean_name}`]({file_url})**<br>_{meta['Source']}_"
            
            table_lines.append(f"| `{folder_display}` | {status_badge} | {notes_cell} | {source_cell} |")
            
    return "\n".join(table_lines) if found_files else "*No .cpp files found.*"

def update_readme(markdown_content):
    try:
        with open("README.md", "r", encoding="utf-8") as f:
            content = f.read()
        pattern = rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}"
        replacement = f"{START_MARKER}\n\n{markdown_content}\n\n{END_MARKER}"
        new_readme = re.sub(pattern, replacement, content, flags=re.DOTALL)
        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_readme)
        print("Success!")
    except Exception as e: print(f"Error: {e}")

if __name__ == "__main__":
    tree = get_repo_tree()
    if tree:
        table = generate_markdown_table(tree)
        update_readme(table)
