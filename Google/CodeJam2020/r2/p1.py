import math

cases = int(input())

def calc_arithmetic_series(a,limit):
    n = math.floor((1-a + math.sqrt(math.pow(a-1,2)+4*limit))/2)
    c = n*(a+n-1)

    return [n,c]

def compare(l,r):
    n = 1
    while(n <= l or n <= r):
        if max(l,r) == l:
            l -= n
        else:
            r -= n
        n += 1

    print(n-1, l, r)

for c in range(1,cases+1):
    l,r = map(int, input().split(' '))
    diff = max(l,r) - min(l,r)
    n1 = math.floor((-1 + math.sqrt(1+8*diff))/2)
    c1 = math.floor(n1*(n1+1)/2)
    if max(l,r) == l:
        l -= c1
    else:
        r -= c1

    if l >= r:
        res_l = calc_arithmetic_series(n1+1, l)
        res_r = calc_arithmetic_series(n1+2,r)
    else:
        res_l = calc_arithmetic_series(n1+2,l)
        res_r = calc_arithmetic_series(n1+1, r)

    l -= res_l[1]
    r -= res_r[1]
    customers_served = n1 + res_l[0] + res_r[0]
    print ("Case #{}: {} {} {}".format(c, customers_served, l, r))

