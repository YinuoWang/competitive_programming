from collections import defaultdict
def main():
    n = int(input())
    graph = defaultdict(list)
    vis = set()
    parents = list(map(int, input().split(' ')))

    for child, parent in enumerate(parents):
        graph[parent].append(child+2)

    # set as default values for leaf
    best_for_start = [1 for i in range(n+1)]
    rem = [0 for i in range(n+1)]
    a_goes_up = [False for i in range(n+1)]

    stack = [1]
    while stack:
        cur = stack[-1]
        # children values already processed
        if cur in vis:
            stack.pop()
            if len(graph[cur]) != 0:
                flip_vals = []
                keep_sum = 0
                rem_sum = 0
                total = 0

                for child in graph[cur]:
                    if not a_goes_up[child]:
                        flip_vals.append((best_for_start[child], rem[child]))
                    else:
                        if rem[child] <= best_for_start[child]:
                            keep_sum += best_for_start[child]
                            rem_sum += rem[child]
                        else:
                            best_for_start[cur] += best_for_start[child]
                    total += best_for_start[child] + rem[child]
                
                # person that doesn't start is going to take control asap
                # without giving away as many coins
                # this keeps going until no more flip branches are available
                flip_vals = sorted(flip_vals, key=lambda x: x[0]-x[1])
                for i, (start_val, rem_val) in enumerate(flip_vals):
                    if i % 2 == 0:
                        best_for_start[cur] += start_val
                    else:
                        best_for_start[cur] += rem_val

                if len(flip_vals) % 2 == 0:
                    best_for_start[cur] += keep_sum
                else:
                    best_for_start[cur] += rem_sum
                    a_goes_up[cur] = True 
                rem[cur] = total + 1 - best_for_start[cur]
        else:
            for child in graph[cur]:
                stack.append(child)
            vis.add(cur)
    print(best_for_start[1])

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