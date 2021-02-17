def topological_sort(digraph):
    n = len(digraph)
    indegree = [0] * n
    for v in range(n):
        for nxt_v in digraph[v]:
            indegree[nxt_v] += 1

    tp_order = [i for i in range(n) if indegree[i] == 0]
    stack = tp_order[:]
    while stack:
        v = stack.pop()
        for nxt_v in digraph[v]:
            indegree[nxt_v] -= 1
            if indegree[nxt_v] == 0:
                stack.append(nxt_v)
                tp_order.append(nxt_v)

    return len(tp_order) == n, tp_order

"""
Slower version since we use dicts instead of lists, but works with any keys instead of only 0 to n-1
If k is a node with no children, then digraph[k] must be set to []
"""
from collections import defaultdict
def topological_sort_dict(digraph):
    n = len(digraph)
    indegree = defaultdict(int)
    for k in digraph:
        for nxt_v in digraph[k]:
            indegree[nxt_v] += 1

    tp_order = [k for k in digraph if indegree[k] == 0]
    stack = tp_order[:]
    while stack:
        v = stack.pop()
        for nxt_v in digraph[v]:
            indegree[nxt_v] -= 1
            if indegree[nxt_v] == 0:
                stack.append(nxt_v)
                tp_order.append(nxt_v)

    return len(tp_order) == n, tp_order