# read input file and seperate into lists of lines
lines = open('input.txt', 'r').readlines()

dict = {}
list1 = []

ans = 0


for line in lines:
    # seperate based on spaces between elements
    parts = line.split()
    # append to list1
    list1.append(int(parts[0]))
    # get frequency of each dict
    if int(parts[1]) in dict:
        dict[int(parts[1])] += 1
    else:
        dict[int(parts[1])] = 1
    

for item in list1:
    # check if its in dict otherwise 0
    if item in dict:
        ans += item * dict[item]

print(ans)