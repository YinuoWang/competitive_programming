import math
X = input()
M = int(input())
d = max(map(int, list(X)))
if len(X) == 1:
    if int(X) <= M:
        print(1)
    else:
        print(0)
else:
    try_num = int(math.ceil((M/int(X[0]))**(1/(len(X)-1))))+20
    while try_num > d:
        total = 0
        cur_pow = try_num**(len(X)-1)
        success = True
        for char in X:
            total += cur_pow * int(char)
            if total > M:
                success = False
                break
            cur_pow //= try_num
        if success:
            break
        try_num -= 1
    print(try_num - d)