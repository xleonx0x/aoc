g = open(0).read().strip().splitlines()

left = False
right = False

numbers = []

letter_numbers = {}
letter_numbers['one'] = 1
letter_numbers['two'] = 2
letter_numbers['three'] = 3
letter_numbers['four'] = 4
letter_numbers['five'] = 5
letter_numbers['six'] = 6
letter_numbers['seven'] = 7
letter_numbers['eight'] = 8
letter_numbers['nine'] = 9

def check_string(string, start):
    three_letter = ''
    four_letter = ''
    five_letter = ''
    if (start < 0):
        start = len(string) + start
    if start + 3 < len(string) + 1:
        three_letter = ''.join(string[start: start + 3])
    if start + 4 < len(string) + 1: 
        four_letter = ''.join(string[start: start + 4])
    if start + 5 < len(string) + 1:
        five_letter = ''.join(string[start: start + 5])
    if (three_letter in letter_numbers):
        return letter_numbers[three_letter]
    elif (four_letter in letter_numbers):
        return letter_numbers[four_letter]
    elif (five_letter in letter_numbers):
        return letter_numbers[five_letter]
    else:
        return False

for r in range(len(g)):
    num = []
    left = False
    right = False
    for c in range(len(g[r])):
        if (left == False and (check_string(g[r], c) or g[r][c].isnumeric())):
            left = True
            if (g[r][c].isnumeric()):
                num.append(g[r][c])
            elif (check_string(g[r], c)):
                num.append(str(check_string(g[r], c)))
            break
    for c in range(len(g[r])):
        if (right == False and (check_string(g[r], -1 - c) or g[r][-1 - c].isnumeric())):
            right = True
            if (g[r][-1 - c].isnumeric()):
                num.append(g[r][-1 - c])
            elif (check_string(g[r], -1 - c)):
                num.append(str(check_string(g[r], -1 - c)))
            break
    if (left == True and right == True):
        numbers.append(int(''.join(num)))

answer = 0
for i in range(len(numbers)):
    answer += numbers[i]

print(str(answer))
