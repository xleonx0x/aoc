import re

a = open(0).read().strip().splitlines()



sum_power = 0
overflow = False

for i in range(len(a)):
    min = {}
    matches = re.findall(r'(\d+) (\w+)', a[i])
    for match in matches:
        if (match[1] in min and int(match[0]) > min[match[1]]):
            min[match[1]] = int(match[0])
        elif (match[1] not in min):
            min[match[1]] = int(match[0])
    if ("red" not in min):
        min["red"] = 1
    if ("blue" not in min):
        min["blue"] = 1
    if ("green" not in min):
        min["green"] = 1
    sum_power += (min["red"] * min["green"] * min["blue"])

print(sum_power)
