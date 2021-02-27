n = int(input())
vis = set()
a = 2
cur_pow = 4
while cur_pow <= n:
    while cur_pow <= n:
        vis.add(cur_pow)
        cur_pow *= a
    a += 1
    cur_pow = a**2
print(n - len(vis))
    