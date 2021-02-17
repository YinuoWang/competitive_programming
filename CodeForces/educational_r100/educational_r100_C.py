def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n = int(input())
        ans = 0
        time, x = map(int, input().split(' '))
        start_time, end_time = 0, 0
        start_pos, end_pos = 0, 0
        for i in range(n):
            if i != n-1:
                next_time, next_x = map(int, input().split(' '))
            else:
                next_time = float('inf')
                next_x = float('inf')
            if time >= end_time:
                start_pos = end_pos
                end_pos = x
                start_time = time
                end_time = abs(end_pos - start_pos) + start_time
                if next_time >= end_time:
                    ans += 1
            # value is actually visited
            elif (start_pos <= x <= end_pos) or (end_pos <= x <= start_pos):
                x_visit_time = abs(start_pos - x)
                if time <= start_time + x_visit_time <= next_time:
                    ans += 1
            time, x = next_time, next_x

        ans_list.append(ans)
    print('\n'.join(map(str,ans_list)))

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