n = int(input())
arr = list(map(int, input().split(' ')))
arr.append(0)

ans = 0
stack = []
for i, val in enumerate(arr):
    prev_index = i 
    while stack and stack[-1][0] > val:
        prev_height, prev_index = stack.pop()
        ans = max(prev_height * (i-prev_index), ans)
    stack.append((val, prev_index))

print(ans)