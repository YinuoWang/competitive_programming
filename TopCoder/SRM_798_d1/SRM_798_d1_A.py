import random
from collections import defaultdict

class BruteForce:
    def solve(self, A, Y):
        MOD = 10**9+7
        d = defaultdict(dict)
        d[0][0] = 1
        for val in A:
            updates = []
            for k in list(d.keys()):
                if k+val <= Y:
                    for occur in d[k]:
                        updates.append((k+val, occur+1, d[k][occur]))

            for key, occur, val in updates:
                if occur in d[key]:
                    d[key][occur] += val
                    d[key][occur] %= MOD
                else:
                    d[key][occur] = val
        ans = 0
        for occur in d[Y]:
            ans += d[Y][occur] * (2**(len(A)-occur)) 
            ans %= MOD
        return ans

class SuperSubset:
    def solve(self, A, Y):
        MOD = 10**9+7
        d = [0 for i in range(Y+1)]
        d[0] = 1
        for val in A:
            new = [d[i]*2 % MOD for i in range(Y+1)]
            for k in range(Y+1):
                if k+val <= Y:
                    new[k+val] += d[k]
                    new[k+val] %= MOD
            d = new
        return d[Y] % MOD

# bf = BruteForce()
# sup_sub = SuperSubset()
# test_arr = [random.randint(1,9999) for i in range(200)]
# print(sup_sub.solve([1,2,3], 3))
# print(sup_sub.solve([1,1,1,1,1], 4))
# print(sup_sub.solve(test_arr, 3000)) 
# print(bf.solve([1,2,3], 3))
# print(bf.solve([1,1,1,1,1], 4))
# print(bf.solve(test_arr, 3000))
