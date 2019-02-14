from collections import defaultdict

class Solution:
    def firstUniqChar(self, s: 'str') -> 'int':
        
        occurrenceDict = defaultdict(int)
        
        for char in s:
            occurrenceDict[char] += 1
            
        for i in range(len(s)):
            if occurrenceDict[s[i]] == 1:
                return i
        
        return -1
