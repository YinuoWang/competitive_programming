n = int(input())
s = input().strip()
x = input().strip()
prev_dp = set([0])
for i in range(n-1, -1, -1):
    new_dp = set()
    for r in range(7):
        cond1 = ((10*r) % 7) in prev_dp
        cond2 = ((10*r + int(s[i])) % 7) in prev_dp
        if x[i] == 'T' and (cond1 or cond2):
            new_dp.add(r)
        elif x[i] == 'A' and cond1 and cond2:
            new_dp.add(r)
    prev_dp = new_dp
print("Takahashi" if 0 in prev_dp else "Aoki")
