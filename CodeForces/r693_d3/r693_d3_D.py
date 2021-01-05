cases = int(input())
ans_list = []
for c in range(cases):
    n = int(input())
    arr = sorted(list(map(int, input().split(' '))))

    a_score, b_score = 0,0
    for i in range(n):
        # Alice's Turn
        if i % 2 == 0:
            a_score += arr[n-1-i] if arr[n-1-i] % 2 == 0 else 0
        # Bob's Turn
        else:
            b_score += arr[n-1-i] if arr[n-1-i] % 2 == 1 else 0
    
    if a_score == b_score:
        ans_list.append("Tie")
    elif a_score < b_score:
        ans_list.append("Bob")
    else:
        ans_list.append("Alice")

print("\n".join(ans_list))
