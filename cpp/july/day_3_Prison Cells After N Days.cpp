class Solution {
public:
    
    vector<int> get_next(vector<int> &cells){
        vector<int> temp(8);
        temp[0] = 0;
        temp[7] = 0;
        for(int i = 1; i < 7; i++){
            temp[i] = cells[i-1] == cells[i+1] ? 1 : 0;
        }
        return temp;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<vector<int>, vector<int>> mp;
        vector<int> temp(8, 0);
        int i, j;
        if(cells[7] || cells[0]){
            temp = get_next(cells);
            mp[cells] = temp;
            cells = temp;
            N--;
        }
        for(j = 0; j < N; j++){
            if(mp.find(cells) == mp.end()){
                temp = get_next(cells);
                mp[cells] = temp;
                cells = temp;
            }else{
                break;
            }
        }
        N = j != 0 ? N%j : 0;
        if(N == 0) return cells;
        for(j = 0; j < N; j++){
            cells = mp[cells];
        }
        return cells;
    }
};
