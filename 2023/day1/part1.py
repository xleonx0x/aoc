g = open(0).read().strip().splitlines()

left = False
right = False

numbers = []

for r in range(len(g)):
    num = []
    left = False
    right = False
    for c in range(len(g[r])):
        if (left == False and g[r][c].isnumeric()):
            left = True
            num.append(g[r][c])
            break
    for c in range(len(g[r])):
        if (right == False and g[r][-1 - c].isnumeric()):
            right = True
            num.append(g[r][-1 - c])
            break
    if (left == True and right == True):
        numbers.append(int(''.join(num)))

answer = 0
for i in range(len(numbers)):
    answer += numbers[i]

print(str(answer))
