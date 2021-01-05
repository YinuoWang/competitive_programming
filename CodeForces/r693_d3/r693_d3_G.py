from collections import defaultdict, deque
import copy
import heapq

def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        input()
        n,m = map(int, input().split(' '))
        adj, inverse_adj = defaultdict(list), defaultdict(list)

        for i in range(m):
            start, end = map(int, input().split(' '))
            adj[start].append(end)
            inverse_adj[end].append(start)
        
        d = [-1 for i in range(n+1)]
        temp_ans = [float('inf') for i in range(n+1)]

        # bfs to compute d, store temp best_answer
        q = deque([1])
        d[1] = 0
        while len(q) > 0:
            cur = q.popleft()
            cur_dist = d[cur]
            temp_ans[cur] = min(temp_ans[cur], cur_dist)
            for edge in adj[cur]:
                if d[edge] != -1:
                    temp_ans[cur] = min(d[edge], temp_ans[cur])
                else:
                    d[edge] = cur_dist + 1
                    q.append(edge)
        heap = [(val, i+1) for i,val in enumerate(temp_ans[1:])]
        heapq.heapify(heap)
        final_ans = [float('inf') for i in range(n+1)]
        while len(heap) > 0:
            val, dfs_start = heapq.heappop(heap)
            if final_ans[dfs_start] != float('inf'):
                continue
            final_ans[dfs_start] = val
            stack = [dfs_start]
            while len(stack) > 0:
                cur = stack.pop()
                for edge in inverse_adj[cur]:
                    if final_ans[edge] == float('inf') and d[cur] > d[edge]:
                        final_ans[edge] = val
                        stack.append(edge) 
        ans_list.append(final_ans[1:])

    for lst in ans_list:
        print(" ".join(list(map(str, lst))))
                
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