cases = int(input())
ans_list = []
for _ in range(cases):
    n = int(input())
    b = input()
    cur_ans = []
    prev_char = '0'
    for char in b:
        if prev_char == '0':
            if char == '1':
                cur_ans.append('1')
                prev_char = '2'
            else:
                cur_ans.append('1')
                prev_char = '1'
        elif prev_char == '1':
            if char == '1':
                cur_ans.append('1')
                prev_char = '2'
            else:
                cur_ans.append('0')
                prev_char = '0'
        else:
            if char == '1':
                cur_ans.append('0')
                prev_char = '1'
            else:
                cur_ans.append('1')
                prev_char = '1'
    ans_list.append(''.join(cur_ans))
print('\n'.join(ans_list))
