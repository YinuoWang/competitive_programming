from collections import Counter

cases = int(input())

ans_list = []
for c in range(cases):
    n = int(input())
    nums = list(map(int, input().split(' ')))
    ans_arr = [0 for i in range(nums[-1]+2)]
    keys = []
    for val in nums:
        ans_arr[val] += 1
        if len(keys) == 0 or keys[-1] != val:
            keys.append(val)
    for k in keys[::-1]:
        if ans_arr[k+1] == 0:
            ans_arr[k+1] = 1
            ans_arr[k] -= 1
    ans = 0
    for i in range(len(ans_arr)):
        if ans_arr[i] != 0:
            ans += 1
    ans_list.append(ans)

for val in ans_list:
    print(val)

