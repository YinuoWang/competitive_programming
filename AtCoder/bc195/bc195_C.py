s = input()
ans = 0
for i in range(len(s)-1):
    ans += (i//3) * (10**(i+1) - 10**i)
power = len(s)-1
ans += (int(s[0])-1) * (10**power) * (power//3)
if len(s) > 1:
    ans += (int(s[1:])+1) * (power//3)
print(ans)