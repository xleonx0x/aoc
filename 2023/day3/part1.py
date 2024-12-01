a = open(0).read().strip().splitlines()

# all the symbols
tools = [[col != "." and not col.isnumeric() for col in row ] for row in a]


print(tools)