class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        memo = [[ -1 for _ in range(amount+1)] for __ in range(len(coins))]
        
        def find(amount, m):
            
            if(amount == 0):
                return 1
            if amount < 0 or (m < 0 and amount >= 1):
                return 0
            if memo[m][amount] != -1:
                return memo[m][amount]
            # print(amount, m)
            memo[m][amount] = find(amount, m-1) + find(amount-coins[m], m)
            
            return memo[m][amount]

        return find(amount, len(coins) - 1)
