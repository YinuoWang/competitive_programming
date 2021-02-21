k = int(input())
ans = 0
# try all the same triples
all_same_val = 1
while all_same_val**3 <= k:
    ans += 1
    all_same_val += 1

two_same_val = 1
two_same_pow = 1
while two_same_pow <= k:
    possible_values = k//two_same_pow
    if possible_values >= two_same_val:
        possible_values -= 1
    ans += 3*possible_values
    two_same_val += 1
    two_same_pow = two_same_val**2

outer_val = 1
while outer_val <= k:
    inner_val = outer_val + 1
    prod = outer_val * inner_val
    div = k//prod
    while div > inner_val:
        ans += 6*(div-inner_val)
        inner_val += 1
        prod = outer_val * inner_val
        div = k//prod
    outer_val += 1
print(ans)
