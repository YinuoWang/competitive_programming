N = int(input())
nums = list(map(int, input().split(' ')))
mx = float('-inf')
ans = 0

for val in nums:
    if val < mx:
        ans += mx - val
    
    mx = max(val, mx)

print(ans)