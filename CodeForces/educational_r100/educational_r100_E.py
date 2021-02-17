from collections import defaultdict

def topological_sort(digraph):
    n = len(digraph)
    indegree = defaultdict(int)
    for k in digraph:
        for nxt_v in digraph[k]:
            indegree[nxt_v] += 1

    tp_order = [k for k in digraph if indegree[k] == 0]
    stack = tp_order[:]
    while stack:
        v = stack.pop()
        for nxt_v in digraph[v]:
            indegree[nxt_v] -= 1
            if indegree[nxt_v] == 0:
                stack.append(nxt_v)
                tp_order.append(nxt_v)

    return len(tp_order) == n, tp_order

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
    n, k = map(int, input().split(' '))
    p = list(map(lambda x: int(x) - 1, input().split(' ')))
    pairs = {}
    uf = UF(n)

    pairs = [-1 for _ in range(n)]
    starting_points = set([i for i in range(n)])
    group_count = n
    for _ in range(k):
        x, y = map(int, input().split(' '))
        x -= 1
        y -= 1
        if uf.find(x) != uf.find(y):
            uf.union(x,y)
            group_count -= 1
        pairs[x] = y
        starting_points.remove(y)
    
    if len(starting_points) != group_count:
        print(0)
        return

    group_ordering = {}
    for sp in starting_points:
        cur_group = uf.find(sp)
        ordering = []
        vis = set()
        cur_node = sp
        while cur_node != -1:
            if cur_node in vis:
                print(0)
                return
            vis.add(cur_node)
            ordering.append(cur_node)
            cur_node = pairs[cur_node]
        group_ordering[cur_group] = ordering

    # check that group ordering is valid
    for group_num, ordering in group_ordering.items():
        vis = set()
        for node in ordering:
            if uf.find(p[node]) == group_num:
                if p[node] != -1 and p[node] not in vis:
                    print(0)
                    return
            vis.add(node)

    graph = {}
    for child, parent in enumerate(p):
        child_group = uf.find(child)
        if child_group not in graph:
            graph[child_group] = []
        if parent != -1:
            parent_group = uf.find(parent)
            if parent_group not in graph:
                graph[parent_group] = []
            if parent_group != child_group:
                graph[parent_group].append(child_group)

    valid, topo_sort = topological_sort(graph)
    if valid:
        ans = []
        for group in topo_sort:
            for node in group_ordering[group]:
                ans.append(str(node+1))
        print(" ".join(ans))
    else:
        print(0)

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