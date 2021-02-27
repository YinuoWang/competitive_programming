from collections import Counter
def compute(tseq, sseq):
    ct, cs = Counter(tseq), Counter(sseq)
    tval, sval = 0, 0
    for i in range(1,10):
        tval += i * 10**(ct[i])
        sval += i * 10**(cs[i])
    return sval > tval

k = int(input())
s,t = input(), input()
numerator = 0
denom = (9 * k - 8) * (9 * k - 9)
rem = [k for _ in range(10)]
for i in range(4):
    rem[int(t[i])] -= 1
    rem[int(s[i])] -= 1

s, t = list(s), list(t)
s[-1], t[-1] = 0, 0
s, t = list(map(int, s)), list(map(int, t))

for last_s in range(1,10):
    s[-1] = last_s
    for last_t in range(1,10):
        t[-1] = last_t
        if compute(t, s):
            if last_s == last_t:
                numerator += rem[last_s] * (rem[last_s] - 1)
            else:
                numerator += rem[last_s] * rem[last_t]

print(numerator/denom)

