# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: 'TreeNode', k: 'int') -> 'int':
        
        stack = [root]
        currentK = 1
        
        while len(stack) != 0:
        
            curNode = stack.pop()
            
            while(curNode != None):
                stack.append(curNode)
                curNode = curNode.left
                
            curNode = stack.pop()
            if currentK == k:
                return curNode.val
            currentK += 1
            stack.append(curNode.right)
            

            