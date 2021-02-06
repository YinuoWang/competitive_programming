from heapq import heappop, heappush

def dijkstra(n, graph, start, conn):
    dist, parents = [float("inf")] * n, [-1] * n
    dist[start] = 0
    ans = float('inf')
    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if (v, start) in conn:
            ans = min(ans, path_len + conn[(v,start)])
        if path_len == dist[v]:
            for w, edge_len in graph[v]:
                if edge_len + path_len < dist[w] and edge_len + path_len < ans:
                    dist[w], parents[w] = edge_len + path_len, v
                    heappush(queue, (edge_len + path_len, w))

    return ans

def main():
    n, m = map(int, input().split(' '))
    graph = [[] for _ in range(n+1)]
    edges = {}
    for _ in range(m):
        a,b,c = map(int, input().split(' '))
        if (a,b) in edges:
            edges[(a,b)] = min(edges[(a,b)], c)
        else:
            edges[(a,b)] = c
    for (a,b), c in edges.items():
        graph[a].append((b, c))
    for i in range(1, n+1):
        res = dijkstra(n+1, graph, i, edges)
        print(res if res != float('inf') else -1)

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