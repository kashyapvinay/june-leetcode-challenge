class Solution:
    def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
        def get_next(cells):
            temp = [0] * 8
            for i in range(1, 7):
                temp[i] = 1 if cells[i-1] == cells[i+1] else 0
            return temp

        mp = dict()
        if(cells[7] or cells[0]):
            temp = get_next(cells)
            mp[str(cells)] = temp
            cells = temp
            N -= 1
        j = 0
        while j < N:
            if not (str(cells) in mp):
                temp = get_next(cells)
                mp[str(cells)] = temp
                cells = temp
            else:
                break
            j += 1
        
        N = (N %j) if j != 0 else 0
        if(N == 0):
            return cells

        for j in range(0, N):
            cells = mp[str(cells)]

        return cells
