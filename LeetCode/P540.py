class Solution:
    def singleNonDuplicate(self, nums: 'List[int]') -> 'int':

        leftPointer = 0
        rightPointer = len(nums)-1
        
        while leftPointer != rightPointer:
            middlePointer = round((leftPointer + rightPointer)/2)
            
            if nums[middlePointer] == nums[middlePointer+1]:
                foundPointer = middlePointer
                
            elif nums[middlePointer] == nums[middlePointer-1]:
                foundPointer = middlePointer - 1
                
            else:
                return nums[middlePointer]
            
            if foundPointer % 2 == 0:
                leftPointer = foundPointer + 2
            else:
                rightPointer = foundPointer - 1
                
        return nums[leftPointer]