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

def get_status_badge(status_raw):
    status = status_raw.upper().strip()
    
    # Define colors
    # For percentages, we "whiten" the green by using lighter hex codes
    if "SOLVED" in status or "ACCEPTED" in status:
        return f"![#00FF00](https://img.shields.io/badge/-**{status}**-00FF00?style=for-the-badge&labelColor=00FF00&logoColor=black)"
    
    if "UNSOLVED" in status or "FAILED" in status:
        return f"![#FF0000](https://img.shields.io/badge/-**{status}**-FF0000?style=for-the-badge&labelColor=FF0000&logoColor=black)"
    
    # Handle percentages (80%, 70%, etc.)
    # We use a lighter green/yellow-green for partial completion
    if "%" in status:
        # Extract number if possible to vary shade, or use a default light green
        return f"![#90EE90](https://img.shields.io/badge/-**{status}**-90EE90?style=for-the-badge&labelColor=90EE90&logoColor=black)"

    # Default fallback
    return f"![#D3D3D3](https://img.shields.io/badge/-**{status}**-D3D3D3?style=for-the-badge&labelColor=D3D3D3&logoColor=black)"

def generate_markdown_table(tree):
    # We are back to a standard table but using Badge Logic for the Status column
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
            
            # Clean filename
            raw_name = os.path.splitext(parts[-1])[0]
            clean_name = raw_name.replace('_', ' ').upper()
            
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            meta = fetch_file_metadata(path)
            
            # Status Badge Logic (Shields.io 'for-the-badge' provides a large, bold block)
            status_badge = get_status_badge(meta['Status'])
            
            # Notes Toggle
            note_raw = meta['Note']
            notes_cell = f"<details><summary>📝 View</summary><br>{note_raw}</details>" if note_raw != "-" else "-"

            # Source & Problem
            source_cell = f"**[`{clean_name}`]({file_url})**<br>_{meta['Source']}_"
            
            table_lines.append(f"| `{folder_display}` | {status_badge} | {notes_cell} | {source_cell} |")
            
    return "\n".join(table_lines) if found_files else "*No .cpp files found.*"

# (Include your existing fetch_file_metadata and update_readme functions here)
