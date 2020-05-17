from collections import deque

case_count = int(input())

for case in range(1,case_count+1):
    c, d = map(int, input().split(' '))
    ordering = list(map(int, input().split(' ')))
    graph = [[0]*(c+1) for i in range(c+1)]
    edges = []
    edge_weight_dict = {}
    for i in range(d):
        n1, n2 = map(int, input().split(' '))
        edges.append((n1, n2))
        graph[n1][n2] = 1
        graph[n2][n1] = 1
    
    q = deque()
    q.append(1)
    marked_nodes = set([1]) 
    while len(q) > 0: 
        cur = q.popleft()
        for i in range(c+1):
            if graph[cur][i] == 1 and (i not in marked_nodes):

                if i not in marked_nodes: 
                    final_weight = -1 * ordering[i-2]
                    if cur == 1:
                        prev_weight = 0
                    else:
                        prev_weight = -1 * ordering[cur-2]
                    edge_weight_dict[(i,cur)] = final_weight - prev_weight
                    edge_weight_dict[(cur,i)] = final_weight - prev_weight
                    marked_nodes.add(i) 
                    q.append(i)
    
    ans = []
    for edge in edges:
        if edge in edge_weight_dict:
            ans.append(str(edge_weight_dict[edge]))
        else:
            ans.append("1000000")
        
    print("Case #{}: {}".format(case, " ".join(ans)))


