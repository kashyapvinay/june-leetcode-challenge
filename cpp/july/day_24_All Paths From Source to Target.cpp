class Solution {
public:
    void dfs(vector<vector<int>> &graph,vector<vector<int>> &res, int s, vector<int> &path){
        if(s == graph.size() - 1){
            path.push_back(graph.size()-1);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(s);
        for(int i = 0; i < graph[s].size(); i++){
            dfs(graph, res, graph[s][i], path);
        }
        path.pop_back();
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, 0, path);
        return res;
    }
};
