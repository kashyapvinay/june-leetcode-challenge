class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        res = []
        indegree = [0] * numCourses
        graph = [[] for _ in range(numCourses)]
        for i in range(len(prerequisites)):
            graph[prerequisites[i][1]].append(prerequisites[i][0])
            indegree[prerequisites[i][0]] += 1
        
        q = deque()
        count = 0
        for i in range(numCourses):
            if(indegree[i] == 0):
                q.append(i)
                res.append(i)
        
        while(q):
            u = q.popleft()
            count += 1
            for i in range(len(graph[u])):
                v = graph[u][i]
                indegree[v] -= 1
                if(indegree[v] == 0):
                    res.append(v)
                    q.append(v)
        
        return res if numCourses == count  else []
