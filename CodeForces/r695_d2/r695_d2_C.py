def main():
    n1, n2, n3 = map(int, input().split(' '))
    lsts = [list(map(int, input().split(' '))), list(map(int, input().split(' '))), list(map(int, input().split(' ')))]
    sums = [sum(lsts[0]), sum(lsts[1]), sum(lsts[2])]
    mins = [min(lsts[0]), min(lsts[1]), min(lsts[2])]
    def comp(i1, i2, i3):
        loc_ans = sums[i1] + sums[i3] - sums[i2]
        if len(lsts[i1]) > 1:
            loc_ans = max(loc_ans, 
                sums[i1] + sums[i3] + sums[i2] - 2*mins[i1] - 2*mins[i2]
            )
        return loc_ans

    ans = 0
    ans = max(comp(0, 1, 2), ans)
    ans = max(comp(0, 2, 1), ans)
    ans = max(comp(1, 0, 2), ans)
    ans = max(comp(1, 2, 0), ans)
    ans = max(comp(2, 1, 0), ans)
    ans = max(comp(2, 0, 1), ans)
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