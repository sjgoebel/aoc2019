file = open("input.txt")

path1 = file.readline()
path2 = file.readline()

path1_instructs = path1.split(",")
path2_instructs = path2.split(",")

grid = {}
cur_x = 0
cur_y = 0
totalsteps = 0

for str in path1_instructs:
    steps = int(str[1:])
    if str[0] == "U":
        for i in range(1,steps + 1):
            cur_x += 0
            cur_y += 1
            totalsteps += 1
            if not (cur_x, cur_y) in grid:
                grid[(cur_x,cur_y)] = [1, totalsteps]
        #stuff
    elif str[0] == "D":
         for i in range(1,steps + 1):
            cur_x += 0
            cur_y += -1
            totalsteps += 1
            if not (cur_x, cur_y) in grid:
                grid[(cur_x,cur_y)] = [1, totalsteps]
        #stuff
    elif str[0] == "L":
         for i in range(1,steps + 1):
            cur_x += -1
            cur_y += 0
            totalsteps += 1
            if not (cur_x, cur_y) in grid:
                grid[(cur_x,cur_y)] = [1, totalsteps]

        #stuff
    else: #Right
         for i in range(1,steps + 1):
            cur_x += 1
            cur_y += 0
            totalsteps += 1
            if not (cur_x, cur_y) in grid:
                grid[(cur_x,cur_y)] = [1, totalsteps]
        #stuff

cur_x = 0
cur_y = 0
distances = []
totalsteps = 0

for str in path2_instructs:

    steps = int(str[1:])
    if str[0] == "U":
        for i in range(1,steps + 1):
            cur_x += 0
            cur_y += 1
            totalsteps += 1
            if (cur_x, cur_y) in grid:
                distances.append(grid.get((cur_x, cur_y))[1] + totalsteps)
                #print(grid.get((cur_x, cur_y))[1])
        #stuff
    elif str[0] == "D":
         for i in range(1,steps + 1):
            cur_x += 0
            cur_y += -1
            totalsteps += 1
            if (cur_x, cur_y) in grid:
                distances.append(grid.get((cur_x, cur_y))[1] + totalsteps)
                #print(grid.get((cur_x, cur_y))[1])

        #stuff
    elif str[0] == "L":
         for i in range(1,steps + 1):
            cur_x += -1
            cur_y += 0
            totalsteps += 1
            if (cur_x, cur_y) in grid:
                distances.append(grid.get((cur_x, cur_y))[1] + totalsteps)
                #print(grid.get((cur_x, cur_y))[1])

        #stuff
    else: #Right
         for i in range(1,steps + 1):
            cur_x += 1
            cur_y += 0
            totalsteps += 1
            if (cur_x, cur_y) in grid:
                distances.append(grid.get((cur_x, cur_y))[1] + totalsteps)
                #print(grid.get((cur_x, cur_y))[1])


#print(grid.items())

'''
for key,value in grid.items():
    if value > 1:
        distances.append(abs(key[0]) + abs(key[1]))
'''
distances.sort()
print(distances[0])