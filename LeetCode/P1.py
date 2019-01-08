class Solution:
    def twoSum(self, nums, target):
        numberDict = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if (complement in numberDict):
                return [i, numberDict[complement]]
            else:
                numberDict[nums[i]] = i