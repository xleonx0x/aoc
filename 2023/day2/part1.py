import re
a = open(0).read().strip().splitlines()

max = {}
max["red"] = 12
max["green"] = 13
max["blue"] = 14

total_ids = 0
overflow = False

for i in range(len(a)):
    overflow = False
    game_round = int(re.search(r'(\d+)', a[i]).group())
    matches = re.findall(r'(\d+) (\w+)', a[i])
    for match in matches:
        if (match[1] in max and int(match[0]) > max[match[1]]):
            overflow = True
            break
    if (not overflow):
        total_ids += int(game_round)

print(total_ids)
