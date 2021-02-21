from heapq import heappop, heappush

def dijkstra(n, graph, start, target):
    """ Uses Dijkstra's algortihm to find the shortest path between in a graph. """
    dist, parents = [float("inf")] * n, [-1] * n
    dist[start] = 0

    queue = [(0, start)]
    while queue:
        path_len, v = heappop(queue)
        if path_len == dist[v]:
            if v == target:
                return dist, parents
            for w, weight, depart_time in graph[v]:
                time_to_dep = depart_time - (path_len % depart_time)
                if time_to_dep == depart_time and time_to_dep >= depart_time:
                    time_to_dep = 0
                total_weight = weight + path_len + time_to_dep
                if total_weight < dist[w]:
                    dist[w], parents[w] = total_weight , v
                    heappush(queue, (total_weight, w))

    return dist, parents

def main():
    n,m,x,y = map(int, input().split(' '))
    x -= 1
    y -= 1
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a,b,t,k = map(int, input().split(' '))
        a -= 1
        b -= 1
        graph[a].append((b,t,k))
        graph[b].append((a,t,k))
    dist, _ = dijkstra(n, graph, x, y)
    if dist[y] == float('inf'):
        print(-1)
    else:
        print(dist[y])

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