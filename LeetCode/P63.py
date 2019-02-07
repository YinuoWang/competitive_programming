class Solution(object):
    
    def uniquePathsWithObstacles(self, obstacleGrid):
        maxRows = len(obstacleGrid)
        maxCols = len(obstacleGrid[0])

        for row in range(maxRows):
            for col in range(maxCols):
                
                if obstacleGrid[row][col] == 1:
                    continue
                    
                if row == 0 and col == 0:
                    obstacleGrid[row][col] = -1
                    continue
                
                if row == 0 or obstacleGrid[row-1][col] == 1:
                    upOptions = 0
                else:
                    upOptions = obstacleGrid[row-1][col]
                
                if col == 0 or obstacleGrid[row][col-1] == 1:
                    leftOptions = 0
                else:
                    leftOptions = obstacleGrid[row][col-1]
                
                obstacleGrid[row][col] = upOptions + leftOptions
        
        if obstacleGrid[row][col] > 0:
            return 0
        else:
            return abs(obstacleGrid[row][col])