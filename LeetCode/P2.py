# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):

        def carryFunc(curList, carry):
            if carry == 0:
                return curList
            elif curList == None:
                return ListNode(1)
            elif curList.val == 9:
                nextNode = ListNode(0)
                nextNode.next = carryFunc(curList.next, 1)
                return nextNode
            else:
                nextNode = ListNode(curList.val + 1)
                nextNode.next = curList.next
                return nextNode

        def addTwoNumbersHelper(l1, l2, carry):
            if l1 == None and l2 == None:
                if carry == 0:
                    return None
                else:
                    return ListNode(carry)
            elif l1 == None:
                return carryFunc(l2, carry)
            elif l2 == None:
                return carryFunc(l1, carry)
            else:
                curSum = l1.val + l2.val + carry
                newNode = ListNode(curSum % 10)
                newNode.next = addTwoNumbersHelper(l1.next, l2.next, curSum // 10)
                return newNode
        return addTwoNumbersHelper(l1, l2, 0)