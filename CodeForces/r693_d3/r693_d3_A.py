cases = int(input())
ans_list = []
for c in range(cases):
    w,h,n = map(int, input().split(' '))
    width_count = 1
    height_count = 1

    while w % 2 == 0:
        width_count *= 2
        w = w//2
    while h % 2 == 0:
        height_count *= 2
        h = h//2
    ans_list.append("YES" if width_count*height_count >= n else "NO")

print("\n".join(ans_list))