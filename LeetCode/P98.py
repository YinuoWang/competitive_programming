def isValidBST_Helper(node, upperLimit, lowerLimit):
    if node == None:
        return True
    
    if node.val <= lowerLimit or node.val >= upperLimit:
        return False
    
    else:
        return isValidBST_Helper(node.left, node.val, lowerLimit) and isValidBST_Helper(node.right, upperLimit, node.val)

class Solution(object):
    def isValidBST(self, root):
        return isValidBST_Helper(root, float('inf'), float('-inf'))