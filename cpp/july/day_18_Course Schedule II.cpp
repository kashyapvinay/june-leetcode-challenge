class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res, indegree(numCourses, 0);
        int i, j, count, u, v;
        vector<vector<int>> graph(numCourses, vector<int>());
        for(i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        count = 0;
        for(i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty()){
            u = q.front();
            q.pop();
            count++;
            for(i = 0; i < graph[u].size(); i++){
                v = graph[u][i];
                indegree[v]--;
                if(indegree[v] == 0){
                    res.push_back(v);
                    q.push(v);
                }
            }
        }
        
        return numCourses == count ? res : vector<int>();
    }
};
