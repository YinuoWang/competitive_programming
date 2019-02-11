# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


def flattenHelp(node, attachment):
    if node.left == None and node.right == None:
        node.right = attachment
    
    elif node.left == None:
        flattenHelp(node.right, attachment)
    
    elif node.right == None:
        node.right = node.left
        flattenHelp(node.right, attachment)
        node.left = None
    
    else:
        node.right = flattenHelp(node.right, attachment)
        node.right = flattenHelp(node.left, node.right)
        node.left = None
      
    return node

class Solution(object):
    
    def flatten(self, root):
        if root != None:
            flattenHelp(root, None)
        