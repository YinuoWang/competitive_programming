def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n = int(input())
        arr = list(map(int, input().split(' ')))

        # prefix[i] means we process i elements
        prefix = [float('inf') for i in range(n+1)]
        prefix[1] = arr[0]
        cur = arr[0]
        for i in range(1, n):
            cur = arr[i] - cur
            if cur < 0:
                break
            prefix[i+1] = cur
        
        # suffix[i] means we have i elements remaining to process
        suffix = [float('inf') for i in range(n)]
        suffix[n-1] = arr[-1]
        cur = arr[-1]
        for i in range(n-2, -1, -1):
            cur = arr[i] - cur
            if cur < 0:
                break
            suffix[i] = cur
        
        if prefix[n] == 0:
            ans = "YES"
        else:
            ans = "NO"
        
        # try and swap the i and i+1th element
        if n != 2: 
            for i in range(n-1):
                if ans == "YES":
                    break
                # only care about suffix
                if i == 0:
                    if arr[0] - suffix[2] == arr[1]:
                        ans = "YES"
                # only care about prefix
                elif i == n-2:
                    if arr[i+1] - prefix[i] == arr[i]:
                        ans = "YES"
                else:
                    res_1 = arr[i+1] - prefix[i]
                    res_2 = arr[i] - suffix[i+2]

                    if res_1 >= 0 and res_1 == res_2:
                        ans = "YES"
        ans_list.append(ans)
    
    print('\n'.join(ans_list))

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