class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        if grid == []:
            return 0
        
        rowCount = len(grid)
        colCount = len(grid[0])
        
        vis = [[0]*colCount for _ in range(rowCount)] 
        
        islandCount = 0
        
        xMove = [1,-1,0,0]
        yMove = [0,0,1,-1]
        
        for row in range(rowCount):
            for col in range(colCount):                
                if int(grid[row][col]) == 1 and vis[row][col] == 0:
                    
                    ## dfs
                    stack = [[row,col]]
                    while not len(stack) == 0:
                        curNode = stack.pop()
                        curRow = curNode[0]
                        curCol = curNode[1]
                        vis[curRow][curCol] = 1
                        
                        for i in range(len(xMove)):
                            if curRow + xMove[i] >= 0 and curRow + xMove[i] < rowCount:
                                if curCol + yMove[i] >= 0 and curCol + yMove[i] < colCount:
                                    newRow = curRow + xMove[i]
                                    newCol = curCol + yMove[i]
                                    
                                    if vis[newRow][newCol] == 0 and int(grid[newRow][newCol]) == 1:
                                        stack.append([newRow,newCol])
                                        
                    islandCount += 1
                    
        return islandCount