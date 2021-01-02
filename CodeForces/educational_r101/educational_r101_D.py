import math
cases = int(input())
ans_list = []
for c in range(cases):
    n = int(input())
    special = [1,2]
    # debug = [i for i in range(n+1)]

    cur = 8
    while cur <= n:
        special.append(cur)
        cur *= 8
    
    if special[-1] != n:
        special.append(n)

    cur_sol_list = []
    special_set = set([val for val in special])
    for i in range(1,n):
        if i not in special_set:
            cur_sol_list.append((i, n))
            # debug[i] = int(math.ceil(debug[i]/debug[n]))

    for i in range(len(special)-1, 2, -1):
        cur_sol_list.append((special[i], special[i-1]))
        # debug[special[i]] = int(math.ceil(debug[special[i]]/debug[special[i-1]]))

    for i in range(len(special)-1, 2, -1):
        cur_sol_list.append((special[i], special[2]))
        # debug[special[i]] = int(math.ceil(debug[special[i]]/debug[special[2]]))

    for i in range(3):
        cur_sol_list.append((special[2], special[1]))
        # debug[special[2]] = int(math.ceil(debug[special[2]]/debug[special[1]]))

    # assert(len(cur_sol_list) <= n+5)
    ans_list.append(cur_sol_list)

for lst in ans_list:
    print(len(lst))
    for x,y in lst:
        print(x,y)

    