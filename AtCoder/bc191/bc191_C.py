h, w = map(int, input().split(' '))
grid = []
for _ in range(h):
    grid.append(input())

ans = 0
# sweep down
heights = [0 for i in range(w)]
for i in range(1, h):
    for j in range(w):
        if grid[i][j] == '#':
            heights[j] += 1
        else:
            heights[j] = 0
    prev = 0
    for height in heights:
        if height == 1 and height != prev:
            ans += 1
        prev = height

# sweep up
heights = [0 for i in range(w)]
for i in range(h-2, 0, -1):
    for j in range(w):
        if grid[i][j] == '#':
            heights[j] += 1
        else:
            heights[j] = 0
    prev = 0
    for height in heights:
        if height == 1 and height != prev:
            ans += 1
        prev = height

# sweep right
widths = [0 for i in range(h)]
for j in range(w):
    for i in range(h):
        if grid[i][j] == '#':
            widths[i] += 1
        else:
            widths[i] = 0
    prev = 0
    for width in widths:
        if width == 1 and width != prev:
            ans += 1
        prev = width

# sweep right
widths = [0 for i in range(h)]
for j in range(w-2, 0, -1):
    for i in range(h):
        if grid[i][j] == '#':
            widths[i] += 1
        else:
            widths[i] = 0
    prev = 0
    for width in widths:
        if width == 1 and width != prev:
            ans += 1
        prev = width

print(ans)
