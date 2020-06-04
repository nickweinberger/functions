# Python file to import contents of a CSV into memory, and output whether or not sequences of strings of DNA are present in memory

from csv import reader
from csv import DictReader
import csv
import sys

if len(sys.argv) != 3:
    print("Usage: two command line arguments")

# Open CSV, read contents into memory
reader = csv.DictReader(open(sys.argv[1]))
original_sequence = open(sys.argv[2]).read()
max_count_dictionary = {}
dnaSequences = []

all_rows = []
for row in reader:
    all_rows.append(row)

reader = csv.DictReader(open(sys.argv[1]))

# Get STRs
for row in reader:
    dnaSequences = [key for key in row]
    dnaSequences.pop(0)

# Get max count for each sequence and fill in max count dictionary with corresponding values
# Got advice from Reese head TA on how to implement count function
counter = 0
max = 0
for sequence in dnaSequences:
    i = 0
    max = 0
    counter = 0
    while (i < len(original_sequence)):
        if original_sequence[i:i+len(sequence)] == sequence:
            counter+=1
            if counter > max:
                max = counter
            i+=len(sequence)
        else:
            counter = 0
            i+=1
        max_count_dictionary[sequence] = max

# Print name if match, print "No match" if not match
match = False
for row in all_rows:
    for sequence in dnaSequences:
        if not (max_count_dictionary[sequence] == int(row[sequence])):
            break
        if sequence is dnaSequences[len(dnaSequences) - 1]:
            match = True
            print(row["name"])
            break
    if match:
        break
if not match:
    print("No match")
