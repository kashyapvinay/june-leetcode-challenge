class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        
        def valid(i, j, m, n):
            return i >= 0 and i < m and j >= 0 and j < n
        
        def dfs(board, i, j, m, n):
            di = [-1, 0, 1, 0]
            dj = [0, 1, 0, -1]
            if(board[i][j] == 'O'):
                board[i][j] = 'Y'
                for l in range(4):
                    pos_i = i + di[l]
                    pos_j = j + dj[l]
                    if(valid(pos_i, pos_j, m, n) and board[pos_i][pos_j] == 'O'):
                        dfs(board, pos_i, pos_j, m, n)

        m = len(board)
        if(m < 2):
            return

        n = len(board[0])

        for i in range(m):
            if(board[i][0] == 'O'):
                dfs(board, i, 0, m, n)

            if(board[i][n-1] == 'O'):
                dfs(board, i, n-1, m, n)

        for i in range(n):
            if(board[0][i] == 'O'):
                dfs(board, 0, i, m, n)

            if(board[m-1][i] == 'O'):
                dfs(board, m-1, i, m, n)
        
        for i in range(m):
            for j in range(n):
                if(board[i][j] == 'O'):
                    board[i][j] = 'X'
                elif(board[i][j] == 'Y'):
                    board[i][j] = 'O'
