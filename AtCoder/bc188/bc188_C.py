N = int(input())
A = list(map(int, input().split(' ')))
A = [(rating, i) for i, rating in enumerate(A)]
while len(A) > 2:
    new_A = []
    i = 0
    while i < 2**N:
        if A[i][0] < A[i+1][0]:
            new_A.append(A[i+1])
        else:
            new_A.append(A[i])
        i += 2
    N -= 1
    A = new_A

print(sorted(A)[0][1]+1)