class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        int i, j, u, v, cost, ans=INT_MAX, new_cost, flag=0;
        for(i = 0; i < flights.size(); i++){
            u = flights[i][0];
            v = flights[i][1];
            cost = flights[i][2];
            graph[u].push_back({v, cost});
        }
        
        queue<pair<int, int>> q;
        pair<int, int> t;
        vector<int> visited(n, INT_MAX);
        q.push({src, 0});
        visited[src] = true;
        while(!q.empty() && K >= 0){
            for(i = q.size()-1; i >= 0; i--){
                t = q.front();
                q.pop();
                for(j = 0; j < graph[t.first].size(); j++){
                    v = graph[t.first][j].first;
                    new_cost = t.second + graph[t.first][j].second;
                    if(v == dst){
                        ans = min(ans, new_cost);
                        flag = 1;
                    }
                    if(visited[v] > new_cost){
                        visited[v] = new_cost;
                        q.push({v, new_cost});
                    }
                }
            }
            K--;
        }
        return flag ? ans: -1;
    }
};
