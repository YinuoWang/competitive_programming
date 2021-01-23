def main():
    N = int(input())
    points = []
    for _ in range(N):
        points.append(tuple(map(int, input().split(' '))))
    M = int(input())
    ops = []
    for _ in range(M):
        ops.append(list(map(int, input().split(' '))))
    queries = []
    Q = int(input())
    for _ in range(Q):
        a, b = map(int, input().split(' '))
        queries.append((a,b-1))
    
    x_slope, x_int, y_slope, y_int, swp = 1, 0, 1, 0, 0
    states = [(x_slope, x_int, y_slope, y_int)]
    for op in ops:
        # apply op
        if op[0] == 1:
            x_slope, x_int, y_slope, y_int, swp = y_slope, y_int, -x_slope, -x_int, 1 ^ swp
        elif op[0] == 2:
            x_slope, x_int, y_slope, y_int, swp = -y_slope, -y_int, x_slope, x_int, 1 ^ swp
        elif op[0] == 3:
            x_slope, x_int = -x_slope, -x_int + 2*op[1]
        else:
            y_slope, y_int = -y_slope, -y_int + 2*op[1]

        states.append((x_slope, x_int, y_slope, y_int, swp))
    
    for a, b in queries:
        x, y = points[b]
        cur_state = states[a]
        if cur_state[-1] == 1:
            x, y = y, x
        x = x*cur_state[0] + cur_state[1]
        y = y*cur_state[2] + cur_state[3]
        print("{} {}".format(x,y))

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