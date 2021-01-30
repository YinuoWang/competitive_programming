import math
n = int(input())
n *= 2
ans = 1
# (b-a+1)(a+b)/2 = n
for i in range(2, math.ceil(math.sqrt(n))):
    if n % i == 0:
        odd_count = 0
        if i % 2 == 1:
            odd_count += 1
        if n // i % 2 == 1:
            odd_count += 1
        if odd_count == 1:
            ans += 1
print(2*ans)

