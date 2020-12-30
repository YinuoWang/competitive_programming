from collections import defaultdict
import heapq

cases = int(input())

ans_list = []
for c in range(cases):
    n = int(input())
    weights = list(map(int, input().split(' ')))

    d = defaultdict(int)
    for i in range(n-1):
        x,y = list(map(int, input().split(' ')))
        d[x] += 1
        d[y] += 1

    cur_sum = sum(weights)
    cur_ans = [cur_sum]
    heap = [(-w, i+1) for i, w in enumerate(weights)]
    heapq.heapify(heap) 
    for k in range(2, n):
        while len(heap) > 0:
            cur_weight, cur_index = -heap[0][0], heap[0][1]
            if d[cur_index] != 1:
                cur_sum += cur_weight
                cur_ans.append(cur_sum)
                d[cur_index] -= 1
                break
            heapq.heappop(heap)

    ans_list.append(cur_ans)

for lst in ans_list:
    print(" ".join(list(map(str, lst))))