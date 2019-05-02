def sub(nextChar):
    if nextChar == '0':
        return 'a'
    else:
        return str(int(nextChar) - 1)

testCaseCount = int(input())

for t in range(testCaseCount):
    n = list(input())
    n = n[::-1]
    a = ""
    b = ""
    for x in range(len(n)):
        curChar = n[x]
        if curChar == '4':
            a += '2'
            b += '2'
        elif curChar == '0':
            if x == len(n) - 1:
                break
            n[x+1] = sub(n[x+1])
            a += '5'
            b += '5'
        elif curChar == 'a':
            n[x+1] = sub(n[x+1])
            a += '2'
            b += '7'
        elif curChar == '1':
            if x == len(n) - 1:
                a += '1'
                break
            n[x+1] = sub(n[x+1])
            a += '6'
            b += '5'
        elif curChar == '5':
            a += '3'
            b += '2'
        else:
            a += str(int(n[x])-1)
            b += '1'
    a = a[::-1]
    b = b[::-1] 
    print("Case #{}: {} {}".format(t+1,a,b))    

