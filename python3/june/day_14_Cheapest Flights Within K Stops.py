class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = [ [] for _ in range(n)]
        for flight in flights:
            u = flight[0]
            v = flight[1]
            cost = flight[2]
            graph[u].append((v, cost,))
        
        q = deque()
        q.append((src, 0))
        visited = [float('inf') for _ in range(n)]
        ans = float('inf')
        while (len(q) > 0 and K >= 0):
            s = len(q)
            for _ in range(s):
                u, cost = q.popleft()
                for j in range(len(graph[u])):
                    v = graph[u][j][0]
                    new_cost = cost + graph[u][j][1]
                    
                    if dst == v:
                        ans = min(new_cost, ans)

                    if new_cost < visited[v]:
                        visited[v] = new_cost
                        q.append((v, new_cost))
            K -= 1      
        return ans if ans != float('inf') else -1
