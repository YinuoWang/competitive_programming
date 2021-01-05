cases = int(input())
ans_list = []
for c in range(cases):
    n = int(input())
    arr = list(map(int, input().split(' ')))
    scores = [0 for i in range(n)]
    vis = [0 for i in range(n)]

    for i, val in enumerate(arr):
        scores[i] += val
        if i+val < n and scores[i] > vis[i+val]:
            scores[i+val] -= vis[i+val]
            scores[i+val] += scores[i]
            vis[i+val] = scores[i]
    
    ans_list.append(str(max(scores)))

print("\n".join(ans_list))