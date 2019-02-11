from collections import defaultdict

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        
        adjacencyDict = defaultdict(list)
        
        # Constructing adjacency matrix
        for edge in edges:
            adjacencyDict[edge[0]].append(edge[1])
            adjacencyDict[edge[1]].append(edge[0])
            
        stack = [0]
        vis = [0] * n
            
        # Finding an endpoint
        while len(stack) > 0:
            currentNode = stack.pop()
            
            for adj in adjacencyDict[currentNode]:
                if vis[adj] == 0 and adj != 0:
                    stack.append(adj)
                    vis[adj] = vis[currentNode] + 1
            
        endPoint = vis.index(max(vis))
        
        diameter = 0
        diameterPath = [endPoint]
        vis = [0] * n
        newStack = [[endPoint, [endPoint]]] 
        
        # Getting the diameter path
        while len(newStack) > 0:
            current = newStack.pop()
            currentNode = current[0]
            currentPath = current[1]
            
            for adj in adjacencyDict[currentNode]:
                if vis[adj] == 0 and adj != endPoint:
                    vis[adj] = vis[currentNode] + 1
                    
                    diameter = max(vis[adj], diameter)

                    newPath = currentPath.copy()
                    newPath.append(adj)
                    
                    if len(newPath) > len(diameterPath):
                        diameterPath = newPath
                    
                    newStack.append([adj, newPath])
    
        answer = []
        for i in range(len(diameterPath)):
            if abs(i - diameter/2.0) < 1:
                answer.append(diameterPath[i])
        
        return answer
            
            