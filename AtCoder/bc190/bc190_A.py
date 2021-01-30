a,b,c = map(int, input().split(' '))
while a > 0 and b > 0:
    if c % 2 == 0:
        a -= 1
    else:
        b -= 1
    c += 1
if a == 0 and b == 0:
    if c % 2 == 0:
        print("Aoki")
    else:
        print("Takahashi")
else:
    if a == 0:
        print("Aoki")
    else:
        print("Takahashi")