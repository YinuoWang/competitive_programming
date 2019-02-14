class Solution:
    def countSubstrings(self, s: 'str') -> 'int':
        isPalindromic = [[0]*len(s) for i in range(len(s))] 
        count = 0
        
        for i in range(len(s)):
            isPalindromic[i][i] = 1
            for j in range(0,i+1):
                if s[j] == s[i]:
                    if i-j <= 1:
                        count+=1
                        isPalindromic[j][i] = 1
                    elif isPalindromic[j+1][i-1]:
                        count += 1
                        isPalindromic[j][i] = 1
        
        return count