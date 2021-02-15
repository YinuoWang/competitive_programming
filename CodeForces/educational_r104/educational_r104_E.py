from collections import defaultdict
def dp_calc(prev_costs, n1, n2, edges, cur_costs):
    new_prev_costs = [(cost, idx+1) for idx, cost in enumerate(prev_costs)]
    new_prev_costs.sort()
    dp = []
    graph = defaultdict(set)
    for start, end in edges:
        graph[end].add(start)
    for i in range(1, n2+1): 
        cur_idx = 0
        while cur_idx < n1 and new_prev_costs[cur_idx][1] in graph[i]:
            cur_idx += 1
        if cur_idx == n1:
            dp.append(float('inf'))
        else:
            dp.append(new_prev_costs[cur_idx][0]+cur_costs[i-1])
    
    return dp

def main():
    n1, n2, n3, n4 = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    b = list(map(int, input().split(' ')))
    c = list(map(int, input().split(' ')))
    d = list(map(int, input().split(' ')))
    m1 = int(input())
    edges1 = []
    for _ in range(m1):
        x, y = map(int, input().split(' '))
        edges1.append((x,y))
    m2 = int(input())
    edges2 = []
    for _ in range(m2):
        x, y = map(int, input().split(' '))
        edges2.append((x,y))
    m3 = int(input())
    edges3 = []
    for _ in range(m3):
        x, y = map(int, input().split(' '))
        edges3.append((x,y))

    b = dp_calc(a, n1, n2, edges1, b)
    c = dp_calc(b, n2, n3, edges2, c)
    d = dp_calc(c, n3, n4, edges3, d)
    ans = min(d)
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)
        
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