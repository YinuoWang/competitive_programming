MOD = 998244353
n,m,k = map(int, input().split(' '))
if n == 1:
    print(pow(k,m,MOD))
elif m == 1:
    print(pow(k,n,MOD))
else:
    ans = 0
    for i in range(1,k+1):
        ans += (pow(i,n,MOD) - pow(i-1,n,MOD)) * pow(k-i+1,m,MOD) % MOD
        ans %= MOD
    print(ans)