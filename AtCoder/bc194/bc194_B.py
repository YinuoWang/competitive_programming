from collections import Counter
ans = float('inf')
n = int(input())
a_lst, b_lst = [], []
for _ in range(n):
    a,b = map(int, input().split(' '))
    ans = min(ans, a+b)
    a_lst.append(a)
    b_lst.append(b)
c_a, c_b = Counter(a_lst), Counter(b_lst)
min_a, min_b = min(a_lst), min(b_lst)
a_idx = a_lst.index(min_a)
b_idx = b_lst.index(min_b)
if c_a[min_a] > 1 or c_b[min_a] > 1 or a_idx != b_idx:
    ans = min(ans, max(min_a, min_b))
else:
    a_slice = a_lst[:a_idx] + a_lst[a_idx+1:]
    b_slice = b_lst[:b_idx] + b_lst[b_idx+1:]
    ans = min(ans, max(min_a, min(b_slice)))
    ans = min(ans, max(min_b, min(a_slice)))
print(ans)