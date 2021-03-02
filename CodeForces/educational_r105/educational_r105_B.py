def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n, u, r, d, l = map(int, input().split(' '))
        if max([u,r,d,l]) <= n-2:
            ans_list.append("YES")
        else:
            min_uc, min_rc, min_dc, min_lc = 0,0,0,0
            if u == n:
                min_rc += 1
                min_lc += 1
            if d == n:
                min_rc += 1
                min_lc += 1
            if r == n:
                min_uc += 1
                min_dc += 1
            if l == n:
                min_uc += 1
                min_dc += 1

            if u < min_uc or r < min_rc or d < min_dc or l < min_lc:
                ans_list.append("NO") 
                continue
        
            if u == n-1:
                if l <= min_lc and r <= min_rc:
                    ans_list.append("NO") 
                    continue
                elif l != min_lc:
                    min_lc += 1
                else:
                    min_rc += 1

            if d == n-1:
                if l <= min_lc and r <= min_rc:
                    ans_list.append("NO") 
                    continue
                elif l != min_lc:
                    min_lc += 1
                else:
                    min_rc += 1

            if r == n-1:
                if u <= min_uc and d <= min_dc:
                    ans_list.append("NO") 
                    continue
                elif u != min_uc:
                    min_uc += 1
                else:
                    min_dc += 1

            if l == n-1:
                if u <= min_uc and d <= min_dc:
                    ans_list.append("NO") 
                    continue
                elif u != min_uc:
                    min_uc += 1
                else:
                    min_dc += 1
            
            if u >= min_uc and d >= min_dc and r >= min_rc and l >= min_lc:
                ans_list.append("YES")
            else:
                ans_list.append("NO")
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