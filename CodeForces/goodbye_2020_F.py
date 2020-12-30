from collections import defaultdict

class UF:
    def __init__(self, N):
        self.par = list(range(N))
        self.sz = [1] * N

    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]

    def union(self, x, y):
        xr, yr = self.find(x), self.find(y)
        if xr == yr:
            return False
        if self.sz[xr] < self.sz[yr]:
            xr, yr = yr, xr
        self.par[yr] = xr
        self.sz[xr] += self.sz[yr]
        return True

    def size(self, x):
        return self.sz[self.find(x)]

    def connected(self, x, y):
        return self.find(x) == self.find(y)

n,m = list(map(int, input().split(' ')))
cur_count = 1
cur_lst = []
uf = UF(m+2)
for i in range(n):
    bit_lst = list(map(int, input().split(' ')))
    bit1 = bit_lst[1]
    bit2 = m+1
    if bit_lst[0] == 2:
        bit2 = bit_lst[2]
    if uf.union(bit1, bit2):
        cur_lst.append(str(i+1))
        cur_count *= 2 
        cur_count %= 10**9 + 7

print(cur_count, len(cur_lst))
print(" ".join(cur_lst))