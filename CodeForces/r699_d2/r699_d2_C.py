from collections import defaultdict
def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n, m = map(int, input().split(' '))
        a = list(map(int, input().split(' ')))
        b = list(map(int, input().split(' ')))
        c = list(map(int, input().split(' ')))

        fail_stack = []
        mismatches = defaultdict(list)
        mismatch_count = 0
        desired = {}
        for i in range(n):
            if a[i] != b[i]:
                mismatch_count += 1
                mismatches[b[i]].append(i)
            desired[b[i]] = i

        cur_ans = [-1 for i in range(m)] 
        for i, color in enumerate(c):
            if mismatches[color]:
                mismatch_count -= 1
                cur_ans[i] = mismatches[color].pop() + 1
                while fail_stack:
                    cur_ans[fail_stack.pop()] = cur_ans[i]
            elif color in desired:
                cur_ans[i] = desired[color] + 1
                while fail_stack:
                    cur_ans[fail_stack.pop()] = cur_ans[i]
            else:
                fail_stack.append(i)
        
        if fail_stack or mismatch_count:
            ans_list.append("NO")
        else:
            ans_list.append("YES")
            ans_list.append(" ".join(map(str, cur_ans)))

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