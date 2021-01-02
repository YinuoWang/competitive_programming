def is_valid(x,y,H,W):
    return x > -1 and y > -1 and x < W and y < H

def dfs(stack, vis_set):
    new_set = set()
    while len(stack) > 0:
        cur_y, cur_x = stack.pop()
        new_set.add((cur_y, cur_x))
        for i in range(4):
            new_y, new_x = cur_y + move_y[i], cur_x + move_x[i]
            if is_valid(new_x, new_y, H,W) and grid[new_y][new_x] == "." and (new_y, new_x) not in vis_set:
                vis_set.add((new_y, new_x))
                stack.append((new_y, new_x))
    
    return new_set
    
H,W = map(int, input().split(' '))
sy, sx = map(int, input().split(' '))
ey, ex = map(int, input().split(' '))
sy -= 1
sx -= 1
ey -= 1
ex -= 1

grid = []

for i in range(H):
    grid.append(input())


move_x = [0,0,1,-1]
move_y = [1,-1,0,0]
tp_x = [0,0,2,-2,1,1,-1,-1,2,2,-2,-2,1,1,-1,-1,2,2,-2,2]
tp_y = [2,-2,0,0,1,-1,1,-1,2,-2,2,-2,2,-2,2,-2,1,-1,1,-1]

stack = [(sy,sx)]
vis_set = set([(sy,sx)])
prev_length = 1
cur_tp = 0
while True:
    tp_set = dfs(stack, vis_set)
    if (ey, ex) in vis_set:
        print(cur_tp)
        break
    
    for cur_y, cur_x in tp_set:
        for i in range(20):
            new_y, new_x = cur_y + tp_y[i], cur_x + tp_x[i]
            if is_valid(new_x, new_y, H,W) and grid[new_y][new_x] == "." and (new_y, new_x) not in vis_set:
                stack.append((new_y, new_x))
                vis_set.add((new_y, new_x))

    cur_tp += 1

    if (ey, ex) in vis_set:
        print(cur_tp)
        break
    
    if prev_length == len(vis_set):
        print(-1)
        break

    prev_length = len(vis_set)
    





