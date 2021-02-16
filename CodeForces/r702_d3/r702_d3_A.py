import math
cases = int(input())
ans_list = []
for _ in range(cases):
    n = int(input())
    a = list(map(int, input().split(' ')))
    ans = 0
    for i in range(n-1):
        big = max(a[i], a[i+1])
        small = min (a[i], a[i+1])
        if big > small * 2:
            test = int(math.log(big/small, 2))
            if big == small * 2**test:
                test -= 1
            ans += test 
    ans_list.append(ans)

print('\n'.join(map(str, ans_list)))
            