def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n, m = map(int, input().split(' '))
        instructions = input()
        prefix, suffix = [(0,0,0)], [(0,0)]
        smallest, largest, cur = 0,0,0
        for char in instructions:
            if char == "+":
                cur += 1
            else:
                cur -= 1
            smallest = min(smallest, cur)
            largest = max(largest, cur)
            prefix.append((smallest, largest, cur))

        smallest, largest = 0,0
        instructions = instructions[::-1]
        if instructions[0] == "+":
            largest += 1
            suffix.append((0,1))
        else:
            smallest -= 1
            suffix.append((-1,0))

        for char in instructions[1:]:
            if char == "-":
                if smallest == suffix[-1][0]:
                    smallest -= 1
                if largest == suffix[-1][1]:
                    largest = max(largest-1, 0)
            else:
                if largest == suffix[-1][1]:
                    largest += 1
                if smallest == suffix[-1][0]:
                    smallest = min(smallest+1, 0)
            suffix.append((smallest, largest))
        suffix = suffix[::-1]

        for q in range(m):
            l, r = map(int, input().split(' '))
            prefix_min, prefix_max, prefix_cur = prefix[l-1]
            suffix_min, suffix_max = suffix[r]

            l_ans = min(prefix_min, prefix_cur+suffix_min)
            r_ans = max(prefix_max, prefix_cur+suffix_max)
            ans_list.append(str(r_ans-l_ans+1))
    
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