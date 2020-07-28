class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        int i, j, total = 0, curr, cycle = n+1;
        for(i = 0; i < tasks.size(); i++){
            counts[tasks[i] - 'A'] += 1;
        }
        priority_queue<int> pq;
        for(i = 0; i < 26; i++){
            if(counts[i]){
                pq.push(counts[i]);
            }
        }
        while(!pq.empty()){
            vector<int> tmp;
            curr = 0;
            for(i = 0; i < cycle; i++){
                if(!pq.empty()){
                    tmp.push_back(pq.top());
                    pq.pop();
                    curr += 1;
                }
            }
            
            for(i = 0; i < tmp.size(); i++){
                tmp[i]--;
                if(tmp[i]){
                    pq.push(tmp[i]);
                }
            }
            total += !pq.empty() ? cycle : curr;
        }
        return total;
    }
};
