# Use math.comb if Python 3.8 is available
def ncr(n, r):
    if 0 <= r <= n:
        r = min(r, n-r)
        numer = reduce(op.mul, range(n, n-r, -1), 1)
        denom = reduce(op.mul, range(1, r+1), 1)
        return numer // denom  
    else:
        return 0