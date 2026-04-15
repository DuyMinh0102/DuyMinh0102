import urllib.request
import json
import re
import urllib.parse
import os
from datetime import datetime

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
        if token:
            req.add_header("Authorization", f"token {token}")
        with urllib.request.urlopen(req) as response:
            return json.loads(response.read().decode())['tree']
    except Exception as e:
        print(f"Error tree: {e}")
        return []

def fetch_file_metadata(file_path):
    raw_url = f"https://raw.githubusercontent.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/{BRANCH}/{urllib.parse.quote(file_path)}"
    metadata = {"Source": "-", "Status": "-", "Note": "-", "Date": "1970-01-01", "DisplayDate": "-"}
    try:
        req = urllib.request.Request(raw_url)
        with urllib.request.urlopen(req) as response:
            lines = response.read().decode('utf-8', errors='ignore').splitlines()
            is_capturing_note = False
            note_lines = []
            
            for line in lines[:60]:
                clean_line = line.strip()
                
                # Parse Date: handles 15/04/2026
                if "Date:" in clean_line:
                    date_match = re.search(r'(\d{1,2}/\d{1,2}/\d{4})', clean_line)
                    if date_match:
                        raw_date = date_match.group(1)
                        try:
                            dt = datetime.strptime(raw_date, "%d/%m/%Y")
                            metadata["Date"] = dt.strftime("%Y-%m-%d")
                            metadata["DisplayDate"] = dt.strftime("%B %d, %Y")
                        except:
                            metadata["Date"] = raw_date
                
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
                    if "*/" in clean_line or "Author:" in clean_line or "Date:" in clean_line:
                        is_capturing_note = False
                        continue
                    if clean_line:
                        note_lines.append(clean_line.replace('|', 'I').lstrip('* '))
            
            if note_lines:
                metadata["Note"] = "<br>".join(note_lines)
        return metadata
    except Exception:
        return metadata

def get_status_badge(status_raw):
    status = status_raw.upper().strip()
    # Clean the status of any manual markdown characters like **
    clean_label = status.replace('*', '').replace('%', '%25')
    
    # Determine the solid background color
    if any(x in status for x in ["UNSOLVED", "FAILED", "WA"]):
        color = "FF0000" # Pure Red
    elif any(x in status for x in ["SOLVED", "ACCEPTED", "AC"]):
        color = "00FF00" # Pure Green
    elif "%" in status:
        color = "90EE90" # Lighter shade of Green
    else:
        color = "D3D3D3" # Grey

    # THE FIX FOR BLACK TEXT:
    # 1. We leave the label empty (the part before the first dash)
    # 2. We set labelColor AND the message color to the same value for a solid block
    # 3. We force logoColor=000000 to trick the renderer into using black contrast
    return f"![{status}](https://img.shields.io/badge/-{clean_label}-{color}?style=for-the-badge&labelColor={color}&logoColor=000000)"

def generate_markdown_table(tree):
    all_data = []
    for item in tree:
        path = item['path']
        if item['type'] == 'blob' and any(path.startswith(f + "/") for f in TARGET_FOLDERS):
            if not path.lower().endswith('.cpp'):
                continue
            meta = fetch_file_metadata(path)
            all_data.append({**item, **meta})

    all_data.sort(key=lambda x: x['Date'], reverse=True)

    # Column order as requested: Folder | Status | Notes | Source & Problem
    table_lines = [
        "| Folder | Status | Notes | Source & Problem |",
        "| :--- | :---: | :---: | :--- |"
    ]
    
    last_date = None
    for item in all_data:
        if item['Date'] != last_date:
            last_date = item['Date']
            table_lines.append(f"| **📅 {item['DisplayDate']}** | | | |")

        parts = item['path'].split('/')
        folder_display = parts[-2].upper()
        # Full capitalization with spaces instead of underscores
        clean_name = os.path.splitext(parts[-1])[0].replace('_', ' ').upper()
        file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(item['path'])}"
        
        status_badge = get_status_badge(item['Status'])
        # Interactive Note toggle
        notes_cell = f"<details><summary>📝 View</summary><br>{item['Note']}</details>" if item['Note'] != "-" else "-"
        # Problem link in the last column
        source_cell = f"**[`{clean_name}`]({file_url})**<br>_{item['Source']}_"
        
        table_lines.append(f"| `{folder_display}` | {status_badge} | {notes_cell} | {source_cell} |")
            
    return "\n".join(table_lines) if all_data else "*No problems found.*"

def update_readme(markdown_content):
    try:
        with open("README.md", "r", encoding="utf-8") as f:
            content = f.read()
        pattern = rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}"
        replacement = f"{START_MARKER}\n\n{markdown_content}\n\n{END_MARKER}"
        new_readme = re.sub(pattern, replacement, content, flags=re.DOTALL)
        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_readme)
        print("Success! Table updated with black-text badges.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    tree = get_repo_tree()
    if tree:
        table = generate_markdown_table(tree)
        update_readme(table)
