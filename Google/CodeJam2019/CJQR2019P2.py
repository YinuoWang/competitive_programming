testCaseCount = int(input())

for t in range(testCaseCount):
    myPos = [0,0]
    herPos = [0,0]
    ans = ""
    size = int(input())
    herPath = input()
    for x in range(len(herPath)):
        if myPos == herPos:
            if herPath[x] == 'E':
                ans += 'S'
                myPos[1] += 1
            else:
                ans += 'E'
                myPos[0] += 1

        else:
            if myPos[0] != myPos[1]:
                if myPos[0] > myPos[1]:
                    ans += 'S'
                    myPos[1] += 1
                else:
                    ans += 'E'
                    myPos[0] += 1
            
            else:
                if herPos[1] > myPos[1]:
                    ans += 'E'
                    myPos[0] += 1
                else:
                    ans += 'S'
                    myPos[1] += 1

        if herPath[x] == 'E':
            herPos[0] += 1
        else:
            herPos[1] += 1

    print("Case #{}: {}".format(t+1,ans))