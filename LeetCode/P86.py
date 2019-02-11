# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        # have a list of the ones smaller
        # have a list of ones bigger
        # combine the two
        
        small = None
        smallStart = None
        bigStart = None
        big = None
        
        cur = head
        
        while cur != None:
            if cur.val >= x:
                if bigStart == None:
                    big = cur
                    bigStart = big
                else:
                    big.next = cur
                    big = big.next
            else:
                if smallStart == None:
                    small = cur
                    smallStart = small
                else:
                    small.next = cur
                    small = small.next       
                    
            cur = cur.next
        
        if small == None or big == None:
            return head
        
        small.next = bigStart

        big.next = None

        return smallStart
