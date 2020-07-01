class Solution:

    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        def dfs(graph, u, res):
            while(len(graph[u])):    
                dfs(graph, graph[u].pop(), res)

            res.append(u)

        graph = defaultdict(list)
        res = []

        for ticket in tickets:
            graph[ticket[0]].append(ticket[1])
        
        for k in graph:
            graph[k].sort(reverse=True)

        u = "JFK"
        dfs(graph, u, res)
        res.reverse()
        return res
