def calc(n):
    if n % 2 == 0:
        return n+1
    else:
        return 2*((n//2)+1)

n = int(input())
if n % 2 == 0:
    print(calc(n//2)**2)
else:
    print((calc(n//2)*calc((n//2)+1))*2)
