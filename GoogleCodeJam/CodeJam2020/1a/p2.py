import math as m

def comb(n,r):
    f = m.factorial
    return f(n) / f(r) / f(n-r)
def want_row(n, row_num):
    return m.pow(2, row_num) + row_num <= n

def generate_row(start_left, row_num):
    output = []
    if start_left:
       for i in range(1, row_num+1):
           output.append((row_num,i))
    else:
       for i in range(row_num, 0, -1):
           output.append((row_num,i))
    return output

def construct_path(rows, left):
    rows_index = 0
    output = []
    start_left = True
    for i in range(1,rows[len(rows)-1]+1):
        if i == rows[rows_index]:
           output.extend(generate_row(start_left, i))
           start_left = not start_left 
           rows_index += 1
        elif start_left:
            output.append((i,1))
        else:
            output.append((i,i))
    max_row = rows[len(rows)-1] + 1
    for i in range(round(left)):
        if start_left:
            output.append((max_row,1))
        else:
            output.append((max_row,max_row))
        max_row += 1
    return output

cases = int(input())
for c in range(1,cases+1):
    n = int(input())
    print("Case #{}:".format(c))
    rows = []
    row_num = m.floor(m.log2(n))
    first_row = True
    while row_num >= 0:
        if want_row(n, row_num):
            n -= m.pow(2, row_num)
            rows.append(row_num+1)
        elif not first_row:
            n -= 1
        row_num -= 1 
        first_row = False
    rows.reverse()
    path = construct_path(rows, n)
    my_sum = 0
    print(len(path))
    for x,y in path:
        my_sum += comb(x-1,y-1)
        print("{} {}".format(x,y))