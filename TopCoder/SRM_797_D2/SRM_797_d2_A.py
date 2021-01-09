class BuyOneGetOneFree:
    def buy(self, prices):
        prices = list(prices)
        prices.sort()
        ans, start_index = 0,0
        n = len(prices)
        if (n % 2) == 1:
            ans += prices[0]
            start_index = 1
        for i in range(start_index, n, 2):
            ans += prices[i+1]
        return ans
