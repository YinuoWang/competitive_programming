cases = int(input())
ans_list = []
for c in range(cases):
    candy_count = int(input())
    weights = sorted(list(map(int, input().split(' '))), reverse=True)
    a_count = 0
    b_count = 0
    for val in weights:
        if a_count <= b_count:
            a_count += val
        else:
            b_count += val
    ans_list.append("YES" if a_count == b_count else "NO")

print("\n".join(ans_list))