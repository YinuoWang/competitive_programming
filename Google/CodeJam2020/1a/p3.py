cases = int(input())

def calculate_interest(grid):
    s = 0
    for row in grid:
        for val in row:
            if val != -1:
                s += val
    return s

def calculate_skill(grid, cur_r, cur_c, r,c):
    move_r = [0,0,1,-1]
    move_c = [1,-1,0,0]
    moves = 0
    cur_sum = 0
    for i in range(4):
        multiplier = 1
        while True: 
            new_r,new_c = cur_r + (move_r[i]*multiplier), cur_c + (move_c[i]*multiplier)
            multiplier += 1
            if new_r >= 0 and new_r < r and new_c >= 0 and new_c < c:
                if grid[new_r][new_c] != -1:
                    moves += 1
                    cur_sum += grid[new_r][new_c]
                    break 
            else:
                break
    if moves == 0:
        return float('-inf') 
    else:
        return cur_sum/moves

for case in range(1, cases+1):
    grid = []
    r,c = map(int, input().split(' '))
    for i in range(r):
        grid.append(list(map(int, input().split(' '))))

    competition_interest = 0
    elimination = True
    while elimination:
        elimination = False
        to_eliminate = []
        competition_interest += calculate_interest(grid)
        for cur_r in range(r):
            for cur_c in range(c):
                if (grid[cur_r][cur_c] != -1):
                    average_skill = calculate_skill(grid, cur_r, cur_c, r,c)
                    if grid[cur_r][cur_c] < average_skill:
                        to_eliminate.append((cur_r, cur_c))
        
        if len(to_eliminate) > 0:
            elimination = True
            for row,col in to_eliminate:
                grid[row][col] = -1

    print("Case #{}: {}".format(case, competition_interest))