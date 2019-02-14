class Solution:
    def coinChange(self, coins: 'List[int]', amount: 'int') -> 'int':
        combinations = [0] + [-1]*(amount)
        MAX = float('inf')
        
        for i in range(1,amount+1):
            
            minCount = MAX
            
            for coin in coins:
                if i - coin >= 0 and combinations[i-coin] != -1:
                    minCount = min(minCount, combinations[i-coin])

            combinations[i] = minCount + 1
        
        if combinations[amount] == float('inf'):
            return -1
        else:
            return combinations[amount]