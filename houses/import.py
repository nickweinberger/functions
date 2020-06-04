from cs50 import SQL
import cs50
import sys
import csv
from csv import DictReader

db = SQL("sqlite:///students.db")

# Check command line arguments
if len(sys.argv) != 2:
    print("Usage: number of command line arguments")

# Create reader from CSV input
reader = csv.DictReader(open(sys.argv[1]))

# Create name list
name_list = []
for row in reader:
    name_list.append(row["name"])
    split_name = row["name"].split()

    first_name = split_name[0]
    if(len(split_name)) == 2:
        last_name = split_name[1]
        middle_name = None
    else:
        last_name = split_name[2]
        middle_name = split_name[1]
    house = row["house"]
    birth = row["birth"]

# Insert into table using SQL
    db.execute(f"INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", first_name, middle_name, last_name, house, birth)