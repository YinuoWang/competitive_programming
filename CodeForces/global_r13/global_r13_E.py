def main():
    n = int(input())
    graph = [[] for _ in range(n+1)]
    parent = [-1 for _ in range(n+1)]
    for _ in range(n-1):
        x,y = map(int, input().split(' '))
        graph[x].append(y)
        graph[y].append(x)
    
    digraph = [[] for _ in range(n+1)]
    stack = [1]
    count_order = []
    while stack:
        cur = stack.pop()
        count_order.append(cur)
        for adj in graph[cur]:
            if parent[cur] == adj:
                continue
            stack.append(adj)
            parent[adj] = cur
            digraph[cur].append(adj)

    count = [1 for _ in range(n+1)]
    while count_order:
        cur = count_order.pop()
        for child in digraph[cur]:
            count[cur] += count[child]

    fib_numbers = [1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418]
    fib_d = {val : i for i, val in enumerate(fib_numbers)}
    fin = [0 for _ in range(n+1)]

    def rec(cur_root, total_nodes):
        if total_nodes <= 3:
            return True
        elif total_nodes not in fib_d:
            return False 

        fib_idx = fib_d[total_nodes]
        search_vals = [fib_numbers[fib_idx-1], fib_numbers[fib_idx-2]]

        cut_node = -1
        stack = [cur_root]
        while stack:
            cur_node = stack.pop()
            if count[cur_node] in search_vals:
                cut_node = cur_node
                fin[cut_node] = True
                break
            for adj in digraph[cur_node]:
                if not fin[adj]:
                    stack.append(adj)
        if cut_node == -1:
            return False
        
        cut_node_count = count[cut_node]

        # propagate update upwards
        cur_parent = parent[cut_node]
        while cur_parent != -1:
            count[cur_parent] -= cut_node_count
            cur_parent = parent[cur_parent]
        parent[cut_node] = -1

        if count[cur_root] <= count[cut_node]:
            try1 = rec(cur_root, count[cur_root])
            if try1:
                return rec(cut_node, count[cut_node])
        else:
            try1 = rec(cut_node, count[cut_node])
            if try1:
                return rec(cur_root, count[cur_root])
        return False

    print("YES" if rec(1, n) else "NO")

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