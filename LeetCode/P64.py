class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        rows = len(grid)
        cols = len(grid[0])
        
        for row in range(rows):
            for col in range(cols):
                if row == 0:
                    upOptions = -1
                else:
                    upOptions = grid[row-1][col]
                
                if col == 0:
                    leftOptions = -1
                else:
                    leftOptions = grid[row][col-1]
                
                if upOptions == -1 and leftOptions == -1:
                        continue
                elif upOptions == -1:
                    grid[row][col] = grid[row][col] + leftOptions
                elif leftOptions == -1:
                    grid[row][col] = grid[row][col] + upOptions
                else:
                    grid[row][col] = grid[row][col] + min(leftOptions, upOptions)
                    
        
        return grid[rows-1][cols-1]