cubes = []
MX = 1e13
cur_val = 1
cur_cube = 1
while cur_cube < MX:
    cubes.append(cur_cube)
    cur_val += 1
    cur_cube = cur_val**3

cubes = set(cubes)

cases = int(input())
ans_list = []
for _ in range(cases):
    x = int(input())
    success = False
    for val in cubes:
        if x - val in cubes:
            success = True
            break
    ans_list.append("YES" if success else "NO")

print('\n'.join(ans_list))