class Solution(object):
    def findMin(self, nums):
        
        leftPointer = 0
        rightPointer = len(nums) - 1
        
        while nums[leftPointer] > nums[rightPointer]:
            middlePointer = int((leftPointer+rightPointer)/2)
            
            if middlePointer == leftPointer:
                if nums[leftPointer] < nums[rightPointer]:
                    rightPointer = leftPointer
                else:
                    leftPointer = rightPointer
            else:
                if nums[middlePointer] > nums[leftPointer]:
                    leftPointer = middlePointer
                else:
                    rightPointer = middlePointer

        return nums[leftPointer]
        