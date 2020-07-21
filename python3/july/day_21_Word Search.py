class Solution:
    
    
    def dfs(self, word, i, j, pos):
        if(pos == len(word) -1):
            return word[pos] == self.board[i][j]

        res = False
        
        if(word[pos] == self.board[i][j]):
            dirc = [[-1, 0], [0, 1], [1, 0], [0, -1]]
            old = self.board[i][j]
            self.board[i][j] = '$'
            for l in range(4):
                pos_i = i + dirc[l][0]
                pos_j = j + dirc[l][1]
                if(pos_i >= 0 and pos_i < len(self.board) and pos_j >= 0 and pos_j < len(self.board[0]) and self.board[pos_i][pos_j] != '$'):
                    res |= self.dfs(word, pos_i, pos_j, pos+1)
                    if(res):
                        return True

            self.board[i][j] = old;

        return res

    def exist(self, board: List[List[str]], word: str) -> bool:
        self.board = board
        for i in range(len(board)):
            for j in range(len(board[0])):
                if(board[i][j] == word[0] and self.dfs(word, i, j, 0)):
                    return True
        return False
