cases = int(input())

ans_list = []
for c in range(cases):
    n = int(input())
    red_nums = list(map(int, input().split(' ')))
    m = int(input())
    blue_nums = list(map(int, input().split(' ')))
    red_sums, blue_sums = [0], [0]
    red_cur, blue_cur = 0,0
    for i in range(n):
        red_cur += red_nums[i]
        red_sums.append(red_cur)
    for i in range(m):
        blue_cur += blue_nums[i]
        blue_sums.append(blue_cur)
    ans_list.append(max(blue_sums)+max(red_sums))

for ans in ans_list:
    print(ans)