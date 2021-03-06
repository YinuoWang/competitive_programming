from collections import defaultdict
def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n = int(input())
        dp = [0 for i in range(n+1)]
        graph = defaultdict(set) 
        edges = list(map(int, input().split(' ')))
        values = list(map(int, input().split()))

        for i, val in enumerate(edges):
            graph[i+2].add(val)
            graph[val].add(i+2)
        
        levels = [[(1,0)]]
        stack = [(1,0)]
        while stack:
            cur_node, cur_level = stack.pop()
            for adj in graph[cur_node]:
                stack.append((adj, cur_level+1))
                graph[adj].remove(cur_node)
                if cur_level + 1 >= len(levels):
                    levels.append([])
                levels[cur_level+1].append((adj, values[adj-2]))

        for l in range(len(levels)-1, -1, -1):
            levels[l] = sorted(levels[l], key=lambda x:x[1])
            neg = float('inf')
            child_max = []
            for (node, val) in levels[l]:
                cur_max = 0
                for child in graph[node]:
                    cur_max = max(dp[child], cur_max)
                child_max.append(cur_max)
            if l == 0:
                ans_list.append(child_max[0])
                break
            cur_best = float('-inf')
            for i, (node, val) in enumerate(levels[l]):
                dp[node] = max(dp[node], cur_best + val)
                cur_best = max(cur_best, child_max[i]-val)
            cur_best = float('-inf')
            for i in range(len(levels[l])-1, -1, -1):
                node, val = levels[l][i]
                dp[node] = max(dp[node], cur_best - val)
                cur_best = max(cur_best, child_max[i]+val)
            for i, (node, val) in enumerate(levels[l]):
                dp[node] = max(
                    dp[node],
                    child_max[i] + max(abs(val-levels[l][0][1]), abs(val-levels[l][-1][1]))
                )
    
    print('\n'.join(map(str, ans_list)))

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