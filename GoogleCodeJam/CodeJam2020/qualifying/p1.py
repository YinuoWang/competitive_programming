cases = int(input())
for c in range(cases):
    n = int(input())
    matrix = []
    for row_count in range(n):
        numbers = input().split(' ')
        row = list(map(int, numbers))
        matrix.append(row)
    
    # calculate trace
    trace = 0
    for i in range(n):
        trace += matrix[i][i]
    
    duplicate_row_count = 0
    for i in range(n):
        cur_set = set()
        for j in range(n):
            cur_set.add(matrix[i][j])
        if len(cur_set) != n:
            duplicate_row_count += 1
            
    duplicate_col_count = 0
    for i in range(n):
        cur_set = set()
        for j in range(n):
            cur_set.add(matrix[j][i])
        if len(cur_set) != n:
            duplicate_col_count += 1

    print("Case #{}: {} {} {}".format(c+1, trace, duplicate_row_count, duplicate_col_count))