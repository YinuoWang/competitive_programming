# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: 'TreeNode') -> 'List[List[int]]':
        
        if root == None:
            return []
        
        returnList = []
        
        stack = [root]
        
        while len(stack) != 0:
            
            addList = []
            for node in stack:
                addList.append(node.val)
            
            returnList.append(addList)
            
            newStack = []
            for node in stack:
                if node.left != None:
                    newStack.append(node.left)
                if node.right != None:
                    newStack.append(node.right)
            
            stack = newStack
        
        return returnList