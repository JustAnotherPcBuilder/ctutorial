import json, pprint, sqlite3

file = "dictionary.json"

with open(file, "r") as f:
    dictionary = json.load(f)
words = [ word for word in list(dictionary.keys()) if not word.startswith('-') ]
words.sort()

conn = sqlite3.connect("dictionary.db")
cursor = conn.cursor()

cursor.execute("""
    CREATE TABLE IF NOT EXISTS words ( 
        word TEXT PRIMARY KEY
    )
""")

cursor.executemany(
    "INSERT OR IGNORE INTO words (word) VALUES (?)",
    [(word,) for word in words]
)

conn.commit()
conn.close()

