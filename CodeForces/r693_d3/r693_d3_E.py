import bisect
def main():
    cases = int(input())
    ans_list = []
    for c in range(cases):
        n = int(input())
        input_arr = []
        for i in range(n):
            w,h = map(int, input().split(' '))
            input_arr.append((w,h,i))

        sort_arr_w = sorted(input_arr)
        sort_arr_h = sorted([(h,w,i) for w,h,i in input_arr])

        width_arr = []
        prefix_min_arr_w = []

        cur_min_i = -1
        cur_min = float('inf')
        for w,h,i in sort_arr_w:
            width_arr.append(w)
            if h < cur_min:
                cur_min = h
                cur_min_i = i
            prefix_min_arr_w.append((cur_min, cur_min_i))

        height_arr = []
        prefix_min_arr_h = []

        cur_min_i = -1
        cur_min = float('inf')
        for h,w,i in sort_arr_h:
            height_arr.append(h)
            if w < cur_min:
                cur_min = w
                cur_min_i = i
            prefix_min_arr_h.append((cur_min, cur_min_i))
        
        cur_ans_lst = []
        for w,h,_ in input_arr: 
            cur_ans = -1

            # try using width
            b_index = bisect.bisect_left(width_arr, w)
            if b_index and h > prefix_min_arr_w[b_index-1][0]:
                cur_ans = prefix_min_arr_w[b_index-1][1] + 1

            # try flipping
            if cur_ans == -1:
                b_index = bisect.bisect_left(height_arr, w)
                if b_index and h > prefix_min_arr_h[b_index-1][0]:
                    cur_ans = prefix_min_arr_h[b_index-1][1] + 1

            cur_ans_lst.append(cur_ans)
        ans_list.append(cur_ans_lst)

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