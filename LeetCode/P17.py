class Solution(object):
    def letterCombinations(self, digits):
        
        masterList = []

        numberDict = {}
        numberDict["2"] = ['a','b','c']
        numberDict["3"] = ['d','e','f']
        numberDict["4"] = ['g','h','i']
        numberDict["5"] = ['j','k','l']
        numberDict["6"] = ['m','n','o']
        numberDict["7"] = ['p','q','r','s']
        numberDict["8"] = ['t','u','v']
        numberDict["9"] = ['w','x','y','z']

        for char in digits:
            if len(masterList) == 0:
                masterList = numberDict[char]
            else:
                newList = []
                for letter in numberDict[char]:
                    for s in masterList:
                        newList.append(s + letter)

                masterList = newList
        
        return masterList
                    