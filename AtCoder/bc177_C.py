import math

N = int(input())
lst = list(map(int, input().split(' ')))
cur_sum = sum(lst)

ans = 0
for val in lst:
    cur_sum -= val
    ans += cur_sum * val
    ans %= (math.floor(math.pow(10,9)) + 7)

ans %= (math.floor(math.pow(10,9)) + 7)
print(ans)
