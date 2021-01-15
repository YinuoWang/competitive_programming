import operator as op
from functools import reduce

class MarbleDrawGame:
    def ncr(self, n, r):
        if 0 <= r <= n:
            r = min(r, n-r)
            numer = reduce(op.mul, range(n, n-r, -1), 1)
            denom = reduce(op.mul, range(1, r+1), 1)
            return numer // denom  
        else:
            return 0

    def winningChance(self, marbles):
        total_marbles = sum(marbles)
        total_combs = self.ncr(total_marbles, 9)
        possible_count = 0
        for marb_count in marbles:
            if marb_count < 5:
                continue
            # i is the number of marbles we draw
            for i in range(5, min(10, marb_count+1)):
                possible_count += self.ncr(marb_count, i) * self.ncr(total_marbles-marb_count, 9-i)
        ans = float(possible_count) / total_combs
        return ans