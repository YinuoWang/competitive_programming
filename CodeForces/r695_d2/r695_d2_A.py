cases = int(input())
ans_list = []
for _ in range(cases):
    ans = []
    n = int(input())
    cur = 8
    for i in range(n):
        if i == 0:
            ans.append("9")
        else:
            ans.append(str(cur))
            cur += 1
            cur %= 10
    ans_list.append("".join(ans))
 
for val in ans_list:
    print(val)