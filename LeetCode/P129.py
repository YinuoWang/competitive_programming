# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):

        def sumHelper(node, acc):
            if node == None:
                return 0
            
            newAcc = 10*acc + node.val

            if node.left == None and node.right == None:
                return newAcc
            
            return sumHelper(node.left, newAcc) + sumHelper(node.right, newAcc)
       
        return sumHelper(root, 0)
        
        