cases = int(input())
for c in range (1, cases+1):
    event_count = int(input())
    event_list = []
    for i in range(event_count):
        start_end = list(map(int, input().split(' ')))
        event_list.append((start_end[0], start_end[1], i))
    
    event_list.sort()
    final_output = ['' for i in range(event_count)]
    c_finish = -1
    j_finish = -1
    is_impossible = False 
    for (start,end,i) in event_list:
        if start >= c_finish:
            c_finish = end
            final_output[i]='C'
        elif start >= j_finish:
            j_finish = end
            final_output[i]='J'
        else:
            is_impossible = True 
            break

    if is_impossible:
        print("Case #{}: IMPOSSIBLE".format(c))
    else:
        print("Case #{}: {}".format(c, ''.join(final_output)))