n, k = map(int, input().split(' '))
for _ in range(k):
    cur_str = sorted(list(str(n)))
    n = int("".join(reversed(cur_str))) - int("".join(cur_str))
print(n)
