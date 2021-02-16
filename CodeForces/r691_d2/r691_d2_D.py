def main():
    MX = 10**4
    n = int(input())
    a, b = [], []
    for _ in range(n):
        cur_capacity, cur_water = map(int, input().split(' '))
        a.append(cur_capacity)
        b.append(cur_water)

    total_water = sum(b)
    # d[i][x] is the max water we can get, with i glasses and x capacity
    d = [[-1 for i in range(MX + 1)] for _ in range(n+1)]
    d[0][0] = 0
    cur_total = 0
    
    for i in range(1, n+1):
        cur_capacity, cur_water = a[i-1], b[i-1]
        cur_total += cur_capacity
        for j in range(i, 0, -1):
            for cap in range(cur_capacity, cur_total + 1):
                prev_cap = d[j-1][cap-cur_capacity]
                if prev_cap != -1:
                    d[j][cap] = max(d[j][cap], prev_cap + cur_water)

    ans_list = []
    for cup_count in range(1, n+1):
        cur_ans = 0
        for cap in range(1, MX + 1):
            max_water = d[cup_count][cap] 
            if max_water != -1:
                rem_water = total_water - max_water
                cur_ans = max(cur_ans, min(cap, max_water + rem_water/2))
        ans_list.append(cur_ans)
            
    print(" ".join(map(str, ans_list)))

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