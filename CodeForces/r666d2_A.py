from collections import defaultdict

N = int(input())
for c in range(N):
    M = int(input())

    char_count = defaultdict(int)

    for i in range(M):
        s = input()

        for char in s:
            char_count[char] += 1

    ans = True
    for _, count in char_count.items():
        if count % M != 0:
            ans = False
            break
    
    if ans:
        print("YES")
    else:
        print("NO")