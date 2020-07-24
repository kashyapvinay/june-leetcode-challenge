class Solution:
        
    def dfs(self, s):
        if(s == len(self.graph) - 1):
            self.path.append(len(self.graph)-1)
            self.res.append(self.path[::])
            self.path.pop()
            return;
        
        self.path.append(s)
        for i in range(len(self.graph[s])):
            self.dfs(self.graph[s][i])
        self.path.pop()

    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.res = []
        self.graph = graph
        self.path = []
        self.dfs(0)
        return self.res
