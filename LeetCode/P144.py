# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: 'TreeNode') -> 'List[int]':
        returnList = []
        stack = [root]
        
        if root == None:
            return []
        
        while len(stack) != 0:
            cur = stack.pop()
            returnList.append(cur.val)
            
            if cur.right != None:
                stack.append(cur.right)
            
            if cur.left != None:
                stack.append(cur.left)
        
        return returnList