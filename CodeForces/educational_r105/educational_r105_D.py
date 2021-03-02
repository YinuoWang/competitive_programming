import heapq
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
    
def main():
    n = int(input())
    uf = UF(n*n+1)
    heap = []
    ans_list = []
    edges = []
    parent_map = {i : i for i in range(n**2 + 1)}

    for i in range(n):
        cur_lst = list(map(int, input().split(' ')))
        for j in range(i, n):
            if i == j:
                ans_list.append(cur_lst[j])
            else:
                heapq.heappush(heap, (cur_lst[j], i, j))

    while heap:
        cur_anc_salary, low1, low2 = heapq.heappop(heap)
        c1, c2 = parent_map[uf.find(low1)], parent_map[uf.find(low2)]
        # already connected
        if c1 == c2:
            continue
        # add kid to c1
        if ans_list[c1] == cur_anc_salary:
           edges.append((c2, c1)) 
           uf.union(c1, c2)
           parent_map[uf.find(c1)] = c1
        elif ans_list[c2] == cur_anc_salary:
           edges.append((c1, c2)) 
           uf.union(c1, c2)
           parent_map[uf.find(c1)] = c2
        else:
            new_node = len(ans_list)
            ans_list.append(cur_anc_salary)
            uf.union(c1, c2)
            uf.union(c1, new_node)
            edges.append((c1, new_node))
            edges.append((c2, new_node))
            parent_map[uf.find(new_node)] = new_node

    print(len(ans_list))
    print(" ".join(map(str, ans_list)))
    print(len(ans_list))
    for x,y in edges:
        print("{} {}".format(x+1, y+1))

# region fastio
import os
import sys
from io import BytesIO, IOBase
BUFSIZE = 8192
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
 
if __name__ == "__main__":
    main()