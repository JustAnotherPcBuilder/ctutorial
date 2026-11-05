import json, pprint, sqlite3

file = "dictionary.json"

with open(file, "r") as f:
    dictionary = json.load(f)
pprint.pprint(dictionary)
exit()
words = list(dictionary.keys())
words.sort()

pprint.pprint(words)

exit()
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

