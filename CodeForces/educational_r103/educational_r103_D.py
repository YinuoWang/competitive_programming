def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n = int(input())
        s = input()
        l_odd, r_odd, l_even, r_even = [1], [1], [1], [1]
        for char in s:
            if char == "L":
                l_even.append(l_odd[-1]+1)
                l_odd.append(1)
            else:
                l_odd.append(l_even[-1]+1)
                l_even.append(1)
        for char in s[::-1]:
            if char == "R":
                r_even.append(r_odd[-1]+1)
                r_odd.append(1)
            else:
                r_odd.append(r_even[-1]+1)
                r_even.append(1)
        r_even, r_odd = r_even[::-1], r_odd[::-1]
        ans = [0 for i in range(n+1)]
        for i in range(n+1):
            ans[i] = l_even[i]+r_even[i]-1
        ans_list.append(ans)

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