cases = int(input())

ans_list = []
for c in range(cases): 
    s = input()
    change = [0 for i in range(len(s))]
    for i in range(1, len(s)):
        change_3 = (s[i] == s[i-2]) if i != 1 else False
        change_2 = (s[i] == s[i-1])
        if change_2 and change[i-1] == 0:
            change[i] = 1
        elif change_3 and change[i-2] == 0:
            change[i] = 1
    ans_list.append(sum(change))

for val in ans_list:
    print(val)
