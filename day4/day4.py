import re

low_pass = 256310
high_pass = 732736

allowed = 0

def correct_pass(word):
    digits = []
    while word > 0:
        digits.append(word % 10)
        word = word // 10

    max_value = len(digits)

    for i in range(1, max_value):
        if digits[i] > digits[i - 1]:
            return False

    repeating = []
    repeating.append(digits[0])
    for i in range(1, max_value):
        if digits[i] == digits[i-1]:
            repeating.append(digits[i])
            if i == max_value - 1:
                if len(repeating) == 2:
                    return True
        else:
            if len(repeating) == 2:
                return True
            else:
                repeating = []
                repeating.append(digits[i])
    return False


for i in range(low_pass, high_pass + 1):
    if (correct_pass(i)):
        allowed += 1


print(allowed)



