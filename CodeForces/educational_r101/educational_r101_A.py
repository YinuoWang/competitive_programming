cases = int(input())

ans_list = []
for i in range(cases):
    line = input()
    if len(line) % 2 == 1:
        ans_list.append("NO")
    else:
        lb_loc = line.index("(")
        rb_loc = line.index(")")
        
        if lb_loc < rb_loc or (lb_loc != len(line)-1 and rb_loc != 0):
            ans_list.append("YES")
        else:
            ans_list.append("NO")

for ans in ans_list:
    print(ans)
