def main():
    cases = int(input())
    ans_list = []
    for _ in range(cases):
        n, m = map(int, input().split(' '))
        graph = []
        for i in range(n):
            graph.append(input())
        pair = None
        for i in range(n):
            for j in range(i+1, n):
                if graph[i][j] == graph[j][i]:
                    pair = (i+1, j+1)
                    break
            if pair is not None:
                break
        
        cur_ans = []
        if pair is not None:
            while m >= 0:
                cur_ans.append(str(pair[m % 2]))
                m -= 1
            ans_list.append("YES")
            ans_list.append(" ".join(map(str, cur_ans)))
        elif m % 2 == 1:
            while m >= 0:
                cur_ans.append((m % 2) + 1)
                m -= 1
            ans_list.append("YES")
            ans_list.append(" ".join(map(str, cur_ans)))
        elif n == 2:
            ans_list.append("NO")
        else:
            start = None
            my_a, my_b = None, None 
            for i in range(n):
                if 'a' in graph[i] and 'b' in graph[i]:
                    start = i+1
                    my_a = graph[i].index('a') + 1
                    my_b = graph[i].index('b') + 1
                    break
            if m % 4 == 0:
                cur_ans.append(start)
                cur_index = 0
                while m > 0:
                    if cur_index == 0:
                        cur_ans.append(my_b)
                    elif cur_index == 1:
                        cur_ans.append(start)
                    elif cur_index == 2:
                        cur_ans.append(my_a)
                    else:
                        cur_ans.append(start)
                    m -= 1
                    cur_index += 1
                    cur_index %= 4
            else:
                cur_index = 0
                cur_ans.append(my_a)
                while m > 0:
                    if cur_index == 0 or cur_index == 2:
                        cur_ans.append(start)
                    elif cur_index == 1:
                        cur_ans.append(my_b)
                    else:
                        cur_ans.append(my_a)
                    m -= 1
                    cur_index += 1
                    cur_index %= 4
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