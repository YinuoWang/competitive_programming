class Solution:
    def subsets(self, nums: 'List[int]') -> 'List[List[int]]':
        outputList = [[]]
        
        for num in nums:
            extendList = []
            
            for lst in outputList:
                copy = lst.copy()
                copy.append(num)
                extendList.append(copy)
        
            outputList.extend(extendList)
            
        return outputList