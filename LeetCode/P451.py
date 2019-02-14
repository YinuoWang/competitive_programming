from collections import defaultdict

class Solution:
    def frequencySort(self, s: 'str') -> 'str':
        
        frequencyLookup = defaultdict(int)
        for i in range(len(s)):
            frequencyLookup[s[i]] += 1
            
        n = len(s)
        arr = [[] for i in range(n+1)]
        
        for entry in frequencyLookup:
            frequencyOfEntry = frequencyLookup[entry]
            
            arr[frequencyOfEntry].append(entry) 
            # {'a' : 3}
            
        returnString = ""
        
        for x in range(n, -1, -1):
            if len(arr[x]) == 0:
                continue
            for char in arr[x]:
                returnString += x * char
        
        return returnString
        