from cs50 import get_string

s = get_string("text: ")

letters = 0
words = 1
sentences = 0

for i in range(len(s)):
    if s[i].isalpha():
        letters+=1
    if s[i].isalpha and s[i-1] == ' ':
        words+=1
    # if s[i] == '"' and s[i-1] == ' ':
    #     words+=1
    if s[i] == '.' or s[i] == '!' or s[i] == '?':
        sentences+=1

(averageletters) = float(letters)/float(words)*100
(averagesentences) = float(sentences)/float(words)*100

x = round(0.0588 * float(averageletters) - 0.296 * float(averagesentences) - 15.8)

if x >= 1 and x <= 16:
    print(f"Grade {x}")
if x > 16:
    print("Grade 16+")
if x < 1:
    print("Before Grade 1")