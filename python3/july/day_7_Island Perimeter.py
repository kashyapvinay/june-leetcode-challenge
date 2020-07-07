class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        direc = [ [-1, 0], [0, 1], [1, 0], [0, -1] ]
    
        ans = 0
        n = len(grid)
        m = len(grid[0])
        vis = [ [ False for __ in range(m) ] for _ in range(n) ]

        q = collections.deque()
        for i in range(n):
            for j in range(m):
                if(grid[i][j] and not vis[i][j]):
                    q.append([i, j])
                    vis[i][j] = True
                    while(len(q)):
                        t = q[0]
                        q.popleft()
                        temp = 4
                        for l in range(4):
                            pos_i = t[0] + direc[l][0]
                            pos_j = t[1] + direc[l][1]
                            if(pos_i >= 0 and pos_i < n and pos_j >= 0 and pos_j < m and grid[pos_i][pos_j]):
                                temp -= 1
                                if(not vis[pos_i][pos_j]):
                                    vis[pos_i][pos_j] = True
                                    q.append([pos_i, pos_j])

                        ans += temp
                    
                    break
        return ans
