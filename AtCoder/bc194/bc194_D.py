n = int(input())
state = 1
ans = 0
while state < n:
    ans += n/(n-state)
    state += 1
print(ans)

