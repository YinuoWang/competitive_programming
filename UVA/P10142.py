import sys

lines = iter(sys.stdin.read().splitlines())

caseCount = int(next(lines))
ansList = []

for _ in range(caseCount):
    for line in lines:
        if line.isdigit():
            candidateCount = int(line)
            break
    
    candidateList = [next(lines) for _ in range(candidateCount)]
    
    entryList = []

    for i, line in enumerate(lines):
        vote = line.split()
        if not vote:
            if not line:
                break
        elif i < 1000:
            entryList.append(list(map(lambda x: int(x) , vote)))
    
    eliminated = {}
    ans = []
    while True:
        results = [0 for i in range(len(candidateList))]    
        for voter in entryList:
            for vote in voter:
                if vote-1 not in eliminated:
                    results[vote-1] += 1
                    break
                  
        if max(results) > (len(entryList)/2):
            for i in range(len(results)):
                if results[i] == max(results):
                    ans.append(candidateList[i])
            ansList.append('\n'.join(ans))
            break
        
        if all((i in eliminated) or (results[i] == max(results)) for i in range(len(results))):
            for i in range(len(results)):
                if i not in eliminated:
                    ans.append(candidateList[i])
            ansList.append('\n'.join(ans))
            break
        
        newMin = float('inf')
        for i in range(len(results)):
            if i not in eliminated:
                newMin = min(newMin, results[i]) 

        for i in range(len(results)):
            if results[i] == newMin:
                eliminated[i] = 1

print('\n\n'.join(ansList))