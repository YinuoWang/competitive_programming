class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        
        for rowNumber in range(len(triangle)):
            if rowNumber == 0:
                continue
            for i in range(len(triangle[rowNumber])):
                if i == 0:
                    triangle[rowNumber][i] = triangle[rowNumber-1][i] + triangle[rowNumber][i]
                elif i == len(triangle[rowNumber]) - 1:
                    triangle[rowNumber][i] = triangle[rowNumber-1][i-1] + triangle[rowNumber][i]
                else:
                    previousStep = min(triangle[rowNumber-1][i], triangle[rowNumber-1][i-1])
                    triangle[rowNumber][i] = triangle[rowNumber][i] + previousStep
        
        minSum = float('inf')
        finalRow = triangle.pop()
        
        for item in finalRow:
            minSum = min(item, minSum)
            
        return minSum
        