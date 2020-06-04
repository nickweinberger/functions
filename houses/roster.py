from cs50 import SQL
import cs50
import sys
import csv
from csv import DictReader

db = SQL("sqlite:///students.db")

# Check command line arguments
if len(sys.argv) != 2:
    print("Usage: number of command line arguments")

# Query database for all students in given house
house_name = sys.argv[1]
name_and_birth_list = db.execute(f"SELECT first, middle, last, birth FROM students WHERE house = '{house_name}' ORDER BY last")

# Print names and birthyears within given house
for row in name_and_birth_list:
    if row["middle"] != None:
        print(row["first"], row["middle"], row["last"] + ", born", row["birth"])
    else:
        print(row["first"], row["last"] + ", born", row["birth"])