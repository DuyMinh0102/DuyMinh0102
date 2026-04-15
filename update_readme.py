import urllib.request
import json
import re
import urllib.parse

# --- CONFIGURATION ---
GITHUB_USERNAME = "DuyMinh0102"
PROBLEMS_REPO = "Competitive_Programming"
BRANCH = "main"
TARGET_FOLDERS = ["Learn", "PTNK", "Train"]

# VISIBLE MARKERS
START_MARKER = ""
END_MARKER = ""
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
        if item['type'] == 'blob' and any(item['path'].startswith(f + "/") for f in TARGET_FOLDERS):
            if item['path'].lower().endswith(('.md', '.png', '.jpg', '.txt')):
                continue
            found_files = True
            path = item['path']
            name = path.split('/')[-1]
            folder = path.split('/')[0]
            url = f"https://github.com/{GITHUB_USERNAME}/{PROBLEMS_REPO}/blob/{BRANCH}/{urllib.parse.quote(path)}"
            
            print(f"Parsing: {name}")
            meta = fetch_file_metadata(path)
            table_lines.append(f"| [{name}]({url}) | `{folder}` | {meta['Source']} | {meta['Status']} | {meta['Note']} |")
            
    return "\n".join(table_lines) if found_files else "*No files found matching criteria.*"

def update_readme(markdown_content):
    try:
        with open("README.md", "r", encoding="utf-8") as f:
            content = f.read()

        if START_MARKER not in content or END_MARKER not in content:
            print(f"⚠️ Markers not found! Make sure {START_MARKER} and {END_MARKER} are in README.md")
            return

        # Regex: find everything between the markers and replace it
        pattern = rf"{re.escape(START_MARKER)}.*?{re.escape(END_MARKER)}"
        new_block = f"{START_MARKER}\n\n{markdown_content}\n\n{END_MARKER}"
        
        updated_content = re.sub(pattern, new_block, content, flags=re.DOTALL)

        with open("README.md", "w", encoding="utf-8") as f:
            f.write(updated_content)
        print("✅ README.md has been updated.")

    except Exception as e:
        print(f"❌ Error: {e}")

if __name__ == "__main__":
    print("🚀 Starting sync...")
    repo_tree = get_repo_tree()
    if repo_tree:
        table = generate_markdown_table(repo_tree)
        update_readme(table)
