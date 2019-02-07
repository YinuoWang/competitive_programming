# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        
        if head == None:
            return None
        
        before_nBack = None
        nBack = head
        cur = head
        
        for i in range(n-1):
            cur = cur.next

        while not cur.next == None:
            before_nBack = nBack
            nBack = nBack.next
            cur = cur.next
        
        if before_nBack == None:
            return head.next
        else:
            before_nBack.next = nBack.next
            return head
            
        