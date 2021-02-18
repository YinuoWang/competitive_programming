from sys import stdout
 
n = int(input())
l,r = 1, n
while l < r:
    print("? {} {}".format(l,r))
    stdout.flush()
    second_max = int(input())
 
    m = (l+r)//2
    # query left half
    if second_max <= m:
        if m == l:
            l += 1
        else:
            print("? {} {}".format(l,m)) 
            stdout.flush()
            comp = int(input())
            if comp != second_max:
                l = m+1
            else:
                r = m
    else:
        if m + 1 == r:
            r -= 1
        else:
            print("? {} {}".format(m+1,r))
            stdout.flush()
            comp = int(input())
            if comp != second_max:
                r = m
            else:
                l = m+1
 
print("! {}".format(l))
stdout.flush()