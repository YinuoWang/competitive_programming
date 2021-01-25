def main():
    cases = int(input()) 
    ans_list = []
    for _ in range(cases):
        n, m = map(int, input().split(' '))
        mem = list(map(int, input().split(' ')))
        conv = list(map(int, input().split(' ')))

        two_list, one_list = [], []
        for i in range(n):
            if conv[i] == 1:
                one_list.append(mem[i])
            else:
                two_list.append(mem[i])
            
        one_list.sort()
        two_list.sort()
        cur_mem, loss = 0, 0
        while cur_mem < m and (one_list or two_list):
            if len(one_list) == 0:
                cur_mem += two_list.pop()
                loss += 2
            elif len(two_list) == 0:
                cur_mem += one_list.pop()
                loss += 1
            elif one_list[-1] + cur_mem >= m:
                cur_mem += one_list.pop()
                loss += 1
            else:
                one_sum = one_list[-1] if len(one_list) == 1 else one_list[-1] + one_list[len(one_list)-2] 
                two_sum = two_list[-1]
                if two_sum > one_sum:
                    cur_mem += two_list.pop()
                    loss += 2
                else:
                    cur_mem += one_list.pop()
                    loss += 1

        if cur_mem < m: 
            ans_list.append(str(-1))
        else:
            ans_list.append(str(loss))
    
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