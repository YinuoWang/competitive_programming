b, c = map(int, input().split(' '))
if c == 0:
    print(1)
elif b == 0:
    print(c)
elif b < 0:
    # calculate how many not in [b, -b]
    ans = (c//2) + (c-1)//2
    # calculate how many in the range
    ans += min((c-1)//2, 2*abs(b)) + 1
    print(ans)
else:
    # calculate how many in [-b, b]
    pos_end = b - (c//2)
    neg_end = -b + (c-1)//2
    if pos_end <= neg_end:
        ans = 2*b + 1
    else:
        ans = neg_end + b + 1 + b - pos_end + 1

    # calculate how many outside the range on negative end
    ans += (c-1)//2 
    # calculate how many outside the range on positive end
    ans += max(0,(c-2))//2 

    print(ans)

        
