from collections import defaultdict

N,M = map(int, input().split(' '))

graph = defaultdict(set)
for i in range(M):
    a,b = map(int, input().split(' '))
    graph[a].add(b)
    graph[b].add(a)

ans = 1
vis_set = set()

for start in graph:
    if start in vis_set:
        continue
    count = 0
    stack = [start]
    vis_set.add(start)
    while len(stack) > 0:
        cur = stack.pop()
        count += 1
        for adj in graph[cur]:
            if adj not in vis_set:
                stack.append(adj)
                vis_set.add(adj)

    ans = max(ans, count)

print(ans)