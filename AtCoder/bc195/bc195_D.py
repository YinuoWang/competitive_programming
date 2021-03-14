n,m,q = map(int, input().split(" "))
bags = []
for _ in range(n):
    w,v = map(int, input().split(' '))
    bags.append((v,w))
bags = sorted(bags, reverse=True)
capacity = list(map(int, input().split(' ')))
ans_list = []
for _ in range(q):
    l,r = map(int, input().split(' '))
    temp_cap = sorted(capacity[:l-1] + capacity[r:], reverse=True)
    taken = [0 for _ in range(len(temp_cap))]
    ans = 0
    for v,w in bags:
        prev = -1 
        for i in range(len(temp_cap)):
            if taken[i] == 0 and w <= temp_cap[i]:
                prev = i
        if prev != -1:
            taken[prev] = 1
            ans += v
    ans_list.append(ans)

print('\n'.join(map(str, ans_list)))