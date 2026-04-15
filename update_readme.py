import urllib.request
import json
import re
import urllib.parse
import os

# --- CONFIGURATION ---
GITHUB_USERNAME = "DuyMinh0102"
PROBLEMS_REPO = "DuyMinh0102"  # Change this from "Competitive_Programming"
BRANCH = "main"

# Since Competitive_Programming is a folder, we must include it in the target paths
TARGET_FOLDERS = [
    "Competitive_Programming/Learn", 
    "Competitive_Programming/PTNK", 
    "Competitive_Programming/Train"
]
# ---------------------

# VISIBLE MARKERS
START_MARKER = "[//]: # (START_TABLE)"
END_MARKER = "[//]: # (END_TABLE)"
# ---------------------

def get_repo_tree():
    url = f"https://api.github.com/repos/{GITHUB_USERNAME}/{PROBLEMS_REPO}/git/trees/{BRANCH}?recursive=1"
    try:
        req = urllib.request.Request(url)
        
        # This looks for the token provided by GitHub Actions
        token = os.getenv("GITHUB_TOKEN")
        if token:
            req.add_header("Authorization", f"token {token}")
            
        with urllib.request.urlopen(req) as response:
            return json.loads(response.read().decode())['tree']
    except Exception as e:
        print(f"Error fetching repo tree: {e}")
        return []

def fetch_file_metadata(file_path):
    # (Keeping your existing logic for fetching metadata)
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
                    if clean_line:
                        note_lines.append(clean_line.replace('|', 'I'))
            if note_lines:
                metadata["Note"] = "<br>".join(note_lines)
        return metadata
    except Exception:
        return metadata

def generate_markdown_table(tree):
    table_lines = [
        "| Problem / File | Folder | Source | Status | Notes |",
        "| :--- | :--- | :--- | :--- | :--- |"
    ]
    found_files = False
    
    for item in tree:
        path = item['path']
        
        # 1. Check if the file is in our target folders
        if item['type'] == 'blob' and any(path.startswith(f + "/") for f in TARGET_FOLDERS):
            
            # 2. ONLY take .cpp files
            if not path.lower().endswith('.cpp'):
                continue
            
            found_files = True
            
            # 3. Get the folder name (e.g., 'Train')
            parts = path.split('/')
            folder_display = parts[1] if len(parts) > 1 else parts[0]
            
            # 4. Get the file name AND strip the extension
            full_file_name = parts[-1]
            display_name = os.path.splitext(full_file_name)[0] # "problem.cpp" -> "problem"
            
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            
            print(f"Parsing: {full_file_name}")
            meta = fetch_file_metadata(path)
            
            table_lines.append(f"| [{display_name}]({file_url}) | `{folder_display}` | {meta['Source']} | {meta['Status']} | {meta['Note']} |")
            
    return "\n".join(table_lines) if found_files else "*No .cpp files found.*"

def update_readme(markdown_content):
    try:
        # 1. Read the current file
        with open("README.md", "r", encoding="utf-8") as f:
            full_text = f.read()

        # 2. Check if markers exist
        if START_MARKER not in full_text or END_MARKER not in full_text:
            print(f"❌ FAILED: Could not find markers in README.md")
            print(f"Make sure your README contains: {START_MARKER}")
            return

        # 3. Use a Regex that handles ANY amount of whitespace/newlines between markers
        # The '?' makes it non-greedy so it doesn't delete the whole file if you have multiple tables
        pattern = rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}"
        
        replacement = f"{START_MARKER}\n\n{markdown_content}\n\n{END_MARKER}"
        
        new_content = re.sub(pattern, replacement, full_text, flags=re.DOTALL)

        # 4. Write back
        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_content)
            
        print("✅ Success! README.md updated.")

    except FileNotFoundError:
        print("❌ Error: README.md not found in this directory.")
    except Exception as e:
        print(f"❌ An unexpected error occurred: {e}")

if __name__ == "__main__":
    print("🚀 Starting sync...")
    repo_tree = get_repo_tree()
    if repo_tree:
        table = generate_markdown_table(repo_tree)
        update_readme(table)
