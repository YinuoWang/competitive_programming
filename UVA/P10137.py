from math import floor,ceil
while True:
    studentCount = int(input())
    if studentCount == 0:
        break
    
    moneyList = []
    for s in range(studentCount):
        moneyList.append(100*float(input()))
    
    avg = sum(moneyList) / len(moneyList)
    avgFloor, avgCeil = floor(avg),ceil(avg)
    aboveSum, belowSum = 0,0

    for num in moneyList:
        if num > avg:
            aboveSum += num - avgCeil
        else:
            belowSum += avgFloor - num
    
    ans = max(aboveSum/100, belowSum/100)
    print("${:.2f}".format(ans))


