# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict



class Solution:
    def findFrequentTreeSum(self, root: 'TreeNode') -> 'List[int]':
        
        instanceDict = defaultdict(int)
        
        def findSumHelper(node):    
            if node == None:
                return 0
            else:
                nonlocal instanceDict 
                
                subTreeSum = node.val + findSumHelper(node.left) + findSumHelper(node.right)
                instanceDict[subTreeSum] += 1
                return subTreeSum
            
        findSumHelper(root)
        
        mostInstancesList = []
        maxInstances = 0
        
        for entry in instanceDict:
            if instanceDict[entry] == maxInstances:
                mostInstancesList.append(entry)
            elif instanceDict[entry] > maxInstances:
                maxInstances = instanceDict[entry]
                mostInstancesList = [entry]
                
        return mostInstancesList


