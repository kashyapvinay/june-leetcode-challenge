class Solution {
public:
    struct TrieNode{
        TrieNode *next[26];
        string word;
    };
    
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    TrieNode* get_node(string w){
        TrieNode *node = new TrieNode();
        for(int i = 0; i < 26; i++){
            node->next[i] = NULL;
        }
        node->word = w;
        return node;
    }

    void dfs(vector<vector<char>>& board, TrieNode *node, int i, int j, vector<string>& res){
        char c = board[i][j];
        if(c == '$' || node->next[c - 'a'] == NULL){
            return;
        }
        node = node->next[c - 'a'];

        if(node->word != ""){
            res.push_back(node->word);
            node->word = "";
        }
        
        board[i][j] = '$';
        int pos_i, pos_j, l;
            
        for(l = 0; l < 4; l++){
            pos_i = i + dir[l][0];
            pos_j = j + dir[l][1];
            if(pos_i >= 0 && pos_i < board.size() && pos_j >= 0 && pos_j < board[0].size() && board[pos_i][pos_j] != '$'){
                dfs(board, node, pos_i, pos_j, res);
            }
        }
        
        
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int i, j, pos;
        vector<string> res;
        TrieNode *root = get_node("");
        for(i = 0; i < words.size(); i++){
            TrieNode *node = root;
            for(j = 0; j < words[i].size(); j++){
                pos = words[i][j]-'a';
                if(node->next[pos] == NULL){
                    node->next[pos] = get_node("");
                }
                node = node->next[pos];
            }
            node->word = words[i];
        }
        
        for(i = 0; i < board.size(); i++){
            for(j = 0; j< board[0].size(); j++){
                TrieNode *node = root;
                dfs(board, node, i, j, res);
            }
        }
        return res;
    }
};
