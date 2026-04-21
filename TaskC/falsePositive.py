import random

def getNumber():
    # Insecure Random flag (false positive)
    numbers = ['82', '56', '31']
    return random.choice(numbers)