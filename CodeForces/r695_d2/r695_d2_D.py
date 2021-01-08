import operator as op
from functools import reduce

def main():
    MOD = 10**9 + 7
    n,k,q = map(int, input().split(' '))
    val_arr = list(map(int, input().split(' ')))

    total_arr = [0 for i in range(n)]
    end_arr = [[0 for j in range(n)] for i in range(k+1)]
    end_arr[0] = [1 for i in range(n)]
    for i in range(1, k+1):
        for j in range(n):
            if j > 0:
                end_arr[i][j] += end_arr[i-1][j-1]
            if j < n-1:
                end_arr[i][j] += end_arr[i-1][j+1]
            end_arr[i][j] %= MOD
        
    for i in range(k+1):
        for j in range(n):
            total_arr[j] += end_arr[i][j] * end_arr[k-i][j]
            total_arr[j] %= MOD
    
    cur_ans = 0
    for i, val in enumerate(total_arr): 
        cur_ans += val * val_arr[i]
        cur_ans %= MOD

    ans_list = []
    for _ in range(q):
        index, new_val = map(int, input().split(' '))
        index -= 1
        cur_ans -= (val_arr[index] * total_arr[index])
        val_arr[index] = new_val
        cur_ans += (val_arr[index] * total_arr[index])
        cur_ans %= MOD
        ans_list.append(cur_ans)
    
    print("\n".join(map(str, ans_list)))

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