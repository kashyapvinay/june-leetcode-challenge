class Solution {
public:
    
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int pos){
        if(pos == word.size() -1){
            return word[pos] == board[i][j];
        }
        bool res = false;
        if(word[pos] == board[i][j]){
            char old = board[i][j];
            board[i][j] = '$';
            int pos_i, pos_j, l;
            
            for(l = 0; l < 4; l++){
                pos_i = i + dir[l][0];
                pos_j = j + dir[l][1];
                if(pos_i >= 0 && pos_i < board.size() && pos_j >= 0 && pos_j < board[0].size() && board[pos_i][pos_j] != '$'){
                    res |= dfs(board, word, pos_i, pos_j, pos+1);
                    if(res){
                        return true;
                    }
                }
            }
            board[i][j] = old;
        }
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int i, j;
        for(i = 0; i < board.size(); i++){
            for(j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0] && dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
