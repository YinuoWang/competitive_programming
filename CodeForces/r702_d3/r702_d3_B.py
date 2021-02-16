def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n = int(input())
        a = list(map(int, input().split(' ')))
        count = [0,0,0]
        for val in a:
            count[val % 3] += 1 
        target = n//3

        final_ans = 0
        # plug this in for 0,1,2
        def modify(a,b,c):
            ans = 0
            if count[a] < target:
                if count[c] > target:
                    add = min(target-count[a], count[c]-target)
                    count[a] += add
                    count[c] -= add
                    ans += add
                if count[a] < target:
                    add2 = min(target-count[a], count[b]-target)
                    count[a] += add2
                    count[b] -= add2
                    ans += 2*add2
            return ans
        
        final_ans += modify(0,1,2)
        final_ans += modify(1,2,0)
        final_ans += modify(2,0,1)
        ans_list.append(final_ans)

    print('\n'.join(map(str, ans_list)))

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