from collections import defaultdict
memo = defaultdict(int)
memo[1] = 1

def compute(num):
    addList = [num]
    while num != 1 and memo[num] == 0:
        if (num % 2) == 1:
            num = 3*num + 1
        else:
            num = num//2
        addList.append(num)

    toAdd = memo[num] - 1
    for i in range(len(addList)):
        curNum = addList[i]
        memo[curNum] = toAdd + len(addList) - i

    return memo[addList[0]]

while True:
    try:
        a,b = map(int, input().split())
        curMax = 0
        for i in range(min(a,b),max(a,b)+1):
            curMax = max(compute(i), curMax)
        
        print(a,b,curMax)
    except:
        break