import urllib.request
import json
import re
import urllib.parse

# --- CONFIGURATION ---
GITHUB_USERNAME = "DuyMinh0102"
PROBLEMS_REPO = "Competitive_Programming"
BRANCH = "main"
TARGET_FOLDERS = ["Learn", "PTNK", "Train"]
# ---------------------

def get_repo_tree():
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
                        note_lines.append(clean_line)
            if note_lines:
                metadata["Note"] = "<br>".join(note_lines)
        return metadata
    except Exception as e:
        print(f"Failed to fetch {file_path}: {e}")
        return metadata

def generate_markdown_table(tree):
    markdown = "| Problem / File | Folder | Source | Status | Notes |\n"
    markdown += "| --- | --- | --- | --- | --- |\n"
    found_files = False

    def generate_markdown_table(tree):
    
    solved_count = sum(1 for item in tree if item['type'] == 'blob' and any(item['path'].startswith(f + "/") for f in TARGET_FOLDERS))

    markdown = f"### ✅ Total Problems Tracked: {solved_count}\n\n"
    markdown += "| Problem / File | Folder | Source | Status | Notes |\n"
    markdown += "| --- | --- | --- | --- | --- |\n"
    
    for item in tree:
        if item['type'] == 'blob' and any(item['path'].startswith(folder + "/") for folder in TARGET_FOLDERS):
            # Ignore README files inside folders
            if item['path'].lower().endswith('.md'): continue
            
            found_files = True
            file_path = item['path']
            file_name = file_path.split('/')[-1]
            folder_name = file_path.split('/')[0]
            file_url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(file_path)}"
            
            print(f"Scanning {file_path}...")
            meta = fetch_file_metadata(file_path)
            markdown += f"| [{file_name}]({file_url}) | `{folder_name}` | {meta['Source']} | {meta['Status']} | {meta['Note']} |\n"
    collapsible_table = f"<details>\n<summary><b>Click to expand my problem log 📋</b></summary>\n\n{markdown}\n</details>"
    return collapsible_table if found_files else "*No problems found.*"

def update_readme(markdown_content):
    try:
        with open("README.md", "r", encoding="utf-8") as f:
            readme = f.read()

        start_marker = ""
        end_marker = ""

        if start_marker not in readme or end_marker not in readme:
            print(f"Error: Markers not found in README.md!")
            return

        # re.escape ensures the special characters in the markers don't break the regex
        pattern = rf"({re.escape(start_marker)}\n)(.*?)(\n{re.escape(end_marker)})"
        replacement = f"\\g<1>{markdown_content}\\g<3>"
        
        new_readme = re.sub(pattern, replacement, readme, flags=re.DOTALL)

        with open("README.md", "w", encoding="utf-8") as f:
            f.write(new_readme)
        print("README updated successfully locally.")
    except Exception as e:
        print(f"Error updating README: {e}")

if __name__ == "__main__":
    print("Fetching repo data...")
    tree = get_repo_tree()
    if tree:
        table = generate_markdown_table(tree)
        
        # --- ADD THIS LINE FOR DEBUGGING ---
        print("GENERATED MARKDOWN TABLE:")
        print(table) 
        # -----------------------------------
        
        update_readme(table)
    else:
        print("Failed to fetch tree.")
