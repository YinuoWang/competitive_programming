cases = int(input())
ans_list = []
for _ in range(cases):
    n = int(input())
    a = list(map(int, input().split(' ')))
    depth = [0 for i in range(n+1)]
    def rec(arr, cur_depth):
        if len(arr) == 0:
            return
        pivot = arr.index(max(arr))
        depth[arr[pivot]] = cur_depth
        rec(arr[:pivot], cur_depth+1)
        rec(arr[pivot+1:], cur_depth+1)
    rec(a, 0)
    cur_ans = []
    for val in a:
        cur_ans.append(depth[val])
    ans_list.append(cur_ans)

for arr in ans_list:
    print(" ".join(map(str, arr)))
        
