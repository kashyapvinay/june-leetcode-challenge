class Solution {
public:
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = {0, 1, 0, -1};

    int valid(int i, int j, int m, int n){
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    void dfs(vector<vector<char>> &board, int i, int j, int m, int n){
        if(board[i][j] == 'O'){
            board[i][j] = 'Y';
            int pos_i, pos_j;
            for(int l = 0; l < 4; l++){
                pos_i = i + di[l];
                pos_j = j + dj[l];
                if(valid(pos_i, pos_j, m, n) && board[pos_i][pos_j] == 'O'){
                    dfs(board, pos_i, pos_j, m, n);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int i, j, m, n;
        m = board.size();
        if(m < 2){
            return;
        }
        n = board[0].size();
        for(i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0, m, n);
            }
            if(board[i][n-1] == 'O'){
                dfs(board, i, n-1, m, n);
            }
        }
        for(i = 0; i < n; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i, m, n);
            }
            if(board[m-1][i] == 'O'){
                dfs(board, m-1, i, m, n);
            }
        }
        
        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
