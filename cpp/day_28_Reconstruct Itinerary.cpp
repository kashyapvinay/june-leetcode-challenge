class Solution {
public:
    void dfs(unordered_map<string, vector<string>> &graph, string u, vector<string> &res){
        
        for(auto it = graph[u].begin(); it != graph[u].end(); ){
            string v = *it;
            graph[u].erase(it);
            dfs(graph, v, res);
        }
        res.push_back(u);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        vector<string> res;
        int i, j;
        string u, v;
        for(i = 0; i < tickets.size(); i++){
            graph[tickets[i][0]].push_back(tickets[i][1]);
        }
        
        for(auto it = graph.begin(); it != graph.end(); it++){
            sort(it->second.begin(), it->second.end());
        }

        u = "JFK";
        dfs(graph, u, res);
        reverse(res.begin(), res.end());
        return res;
    }
};
