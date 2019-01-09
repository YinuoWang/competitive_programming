class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        lp = 0
        rp = 0
        curMax = 0
        indexDict = {}
        while (rp < l):

            if s[rp] in indexDict:
                curMax = max(curMax, rp-lp)
                
                if (s[rp] == s[lp]):
                    lp += 1
                else:
                    while (not s[lp] == s[rp]):
                        del indexDict[s[lp]]
                        lp += 1
                    lp += 1

            indexDict[s[rp]] = rp
            rp += 1

        curMax = max(curMax, rp-lp)
        return curMax
