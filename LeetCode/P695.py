class Solution(object):
    def maxAreaOfIsland(self, grid):
        
        if grid == []:
            return 0
        
        rowCount = len(grid)
        colCount = len(grid[0])
        
        vis = [[0]*colCount for _ in range(rowCount)] 
        
        maxIsland = 0
        
        xMove = [1,-1,0,0]
        yMove = [0,0,1,-1]
        
        for row in range(rowCount):
            for col in range(colCount):                
                if grid[row][col] == 1 and vis[row][col] == 0:
                    
                    ## dfs
                    islandSize = 0
                    vis[row][col] = 1
                    stack = [[row,col]]
                    
                    while not len(stack) == 0:
                        curNode = stack.pop()
                        
                        curRow = curNode[0]
                        curCol = curNode[1]
                        
                        islandSize += 1
                        
                        for i in range(len(xMove)):
                            if curRow + xMove[i] >= 0 and curRow + xMove[i] < rowCount:
                                if curCol + yMove[i] >= 0 and curCol + yMove[i] < colCount:
                                    newRow = curRow + xMove[i]
                                    newCol = curCol + yMove[i]
                                    
                                    if vis[newRow][newCol] == 0 and grid[newRow][newCol] == 1:
                                        vis[newRow][newCol] = 1
                                        stack.append([newRow,newCol])

                    maxIsland = max(islandSize, maxIsland)
        
        return maxIsland