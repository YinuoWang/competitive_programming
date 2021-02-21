from collections import defaultdict
S = input()
n = len(S)
duplicates = []
i = 0
while i < n - 2:
    if S[i] == S[i+1]:
        duplicates.append(i)
    i += 1
ans = 0
d = defaultdict(int)
i = n - 1
while i >= 0:
    cur_char = S[i]
    d[cur_char] += 1
    if duplicates and i == duplicates[-1]:
        ans += n - i - d[cur_char]
        d.clear()
        d[cur_char] = n - i 
        duplicates.pop()
    i -= 1
print(ans)
