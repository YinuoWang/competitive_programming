def main():
    def test(i):
        if i == 0 or i == len(arr)-1:
            return 0
        if (arr[i-1] < arr[i] and arr[i+1] < arr[i]) or (arr[i-1] > arr[i] and arr[i+1] > arr[i]):
            return 1
        return 0
    ans_list = []
    cases = int(input())
    for _ in range(cases):
        n = int(input())
        arr = list(map(int, input().split(' ')))
        if n < 3:
            ans_list.append(0)
        else:
            count = 0
            check_arr = [0]
            for i in range(1, n-1):
                test_val = test(i)
                check_arr.append(test_val)
                count += test_val
            check_arr.append(0)

            ans = count
            for i, val in enumerate(check_arr):
                if i == 0 or i == n-1:
                    continue
                else:
                    save = arr[i]
                    arr[i] = arr[i-1]
                    ans = min(ans, 
                        count - check_arr[i] - check_arr[i-1] - check_arr[i+1] + test(i) + test(i-1) + test(i+1)
                    )

                    arr[i] = arr[i+1]
                    ans = min(ans, 
                        count - check_arr[i] - check_arr[i-1] - check_arr[i+1] + test(i) + test(i-1) + test(i+1)
                    )
                    arr[i] = save
            ans_list.append(ans)
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