import sys
input = sys.stdin.readline

cases = int(input())
ans_list = []
for c in range(1, cases+1):
    n, k = map(int, input().split(' '))
    s = input()
    l,r = 0, n-1
    goodness = 0
    while l < r:
        if s[l] != s[r]:
            goodness += 1
        l += 1
        r -= 1
    ans = abs(goodness - k)
    ans_list.append("Case #{}: {}".format(c, ans))
print('\n'.join(ans_list))