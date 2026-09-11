#!/home/luis/.pyenv/shims/python

from pathlib import Path

file = "README.md"

with open(file, 'r') as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if "## Projects" in line:
        start = i
        break

for i, line in enumerate(lines[start + 1:]):
    if line.startswith("## "):
        end = i
        break

questions = []
current = None
for line in lines[start:start+end]:
    if line.startswith("### "):
        current = {"Title": line, "Body": []}
        questions.append(current)
    else:
        if current is not None:
            current["Body"].append(line)
for i, question in enumerate(questions):
    dir = f"{i+1:02}-" + question.get("Title").replace("### ", "").replace(" ", "").replace("\n", "")
    Path(dir).mkdir(parents=True, exist_ok=True)
    with open(f"{dir}/readme.md", "w") as f:
        f.write(question.get("Title"))
        f.writelines(question.get("Body"))
