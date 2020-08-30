S = input()
T = input()

ans = float('inf')
for i in range(len(S)-len(T)+1):
    diff_count = 0
    for j in range(len(T)):
        if S[i+j] != T[j]:
            diff_count += 1

    ans = min(ans, diff_count)

print(ans)
        