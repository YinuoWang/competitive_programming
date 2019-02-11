class Solution:
    def gameOfLife(self, board: 'List[List[int]]') -> 'None':
    
        if len(board) == 0:
            return
        
        xMove = [1,1,1,-1,-1,-1,0,0]
        yMove = [-1,0,1,-1,0,1,1,-1]
        
        rowCount = len(board)
        colCount = len(board[0])
        
        for row in range(rowCount):
            for col in range(colCount):
                liveCount = 0
                
                for i in range(len(xMove)):
                    if row + xMove[i] >= 0 and row + xMove[i] < rowCount:
                        if col + yMove[i] >=0 and col + yMove[i] < colCount:
                            newRow = row + xMove[i]
                            newCol = col + yMove[i]
                            
                            if board[newRow][newCol] == 1 or board[newRow][newCol] == -1:
                                liveCount += 1
            
                if board[row][col] == 0:
                    if liveCount == 3:
                        board[row][col] = 2
                elif board[row][col] == 1:
                    if liveCount > 3 or liveCount < 2:
                        board[row][col] = -1
                        
        for row in range(rowCount):
            for col in range(colCount):
                if board[row][col] == -1:
                    board[row][col] = 0
                elif board[row][col] == 2:
                    board[row][col] = 1