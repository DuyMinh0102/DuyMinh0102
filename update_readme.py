import os
import urllib.parse
import urllib.request
import json
import re

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

def generate_markdown_table(tree):
    # Header: Problem column is GONE
    table_lines = [
        "| Problem | Source & Problem | Status | Notes |",
        "| :--- | :--- | :--- | :--- |"
    ]
    found_files = False
    
    for item in tree:
        path = item['path']
        if item['type'] == 'blob' and any(path.startswith(f + "/") for f in TARGET_FOLDERS):
            if not path.lower().endswith('.cpp'):
                continue
            
            found_files = True
            parts = path.split('/')
            
            # 1. Folder name fully capitalized (e.g., TRAIN)
            folder_display = parts[-2].upper() if len(parts) > 1 else "ROOT"
            
            # 2. File name without extension
            display_name = os.path.splitext(parts[-1])[0]
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            
            meta = fetch_file_metadata(path)
            
            # 3. Use <details> for the Notes button
            note_content = meta['Note']
            if note_content and note_content != "-":
                formatted_note = f"<details><summary>📁 View</summary><br>{note_content}</details>"
            else:
                formatted_note = "-"

            # 4. Put the Problem Link in the Source column
            # Shows: ProblemName 
            #        SourceInfo
            source_cell = f"**[{display_name}]({file_url})**<br>_{meta['Source']}_"
            
            table_lines.append(f"| `{folder_display}` | {source_cell} | {meta['Status']} | {formatted_note} |")
            
    return "\n".join(table_lines) if found_files else "*No .cpp files found.*"

# ... (rest of your existing get_repo_tree, fetch_file_metadata, and update_readme functions)
