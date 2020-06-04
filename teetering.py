# Idea for permutations found at https://www.geeksforgeeks.org/generate-all-the-permutation-of-a-list-in-python/
from itertools import permutations

# Accepts one parameter, returns True if array is balanceable
def balanceable(numbers):
    permutations = create_permutations(numbers)
    for item in permutations:
        if_item_is_balanced = is_balanced(item)
        if if_item_is_balanced == True:
            return True
    return False

# Creates all possible permutations of array "numbers"
def create_permutations(numbers):
    l = list(permutations(numbers))
    return l

# Determines whether an array is balanceable
def is_balanced(numbers):

    print(numbers)
    for i in range(len(numbers)):
        if sum(numbers[0:i]) == sum(numbers[i:len(numbers)]):
            return True
    return False

# Used for testing

# def main():
#     output = balanceable()
#     print(output)

# main()