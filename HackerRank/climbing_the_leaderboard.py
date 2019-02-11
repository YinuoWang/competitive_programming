#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):

    rankingDict = {}
    currentRanking = 1
    aliceRankings = []

    for score in scores:
        if score in rankingDict:
            continue
        else:
            rankingDict[score] = currentRanking
        currentRanking += 1
    
    scores.reverse()

    start = 0

    for aliceScore in alice:
        newStart = start

        for i in range(start, len(scores)):
            if scores[i] == aliceScore:
                aliceRankings.append(rankingDict[scores[i]])
                break
            elif scores[i] > aliceScore:
                aliceRankings.append(rankingDict[scores[i]]+1)
                break
            else:
                newStart += 1

        start = newStart
        
        if start == len(scores):
            aliceRankings.append(1)
        
    return aliceRankings

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
