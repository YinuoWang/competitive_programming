# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        
        # go to the m-1th node
        curNode = head
        for i in range(m-2):
            curNode = curNode.next
            
        if m == 1:
            m_1thNode = None
            mthNode = curNode
        else:
            m_1thNode = curNode
            mthNode = curNode.next

        prevNode = None
        curNode = mthNode
        
        # reverse the linked list as normal here, our curnode will be our n+1th node
        for i in range(m,n+1):
            nextNode = curNode.next
            curNode.next = prevNode
            prevNode = curNode
            curNode = nextNode
        
        mthNode.next = curNode
        if m == 1:
            return prevNode
        else:
            m_1thNode.next = prevNode
            return head
        
    """
    m-1thNode.next = nth node
    mthNode.next = n+1th node
    """
        