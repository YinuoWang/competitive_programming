import math
a,b,w = map(int, input().split(' '))
w *= 1000
max_count = w//a
min_count = w//b

if w % b != 0:
    min_count += 1

if math.ceil((w % a)/max_count) + a > b:
    print("UNSATISFIABLE")
else:
    print("{} {}".format(min_count, max_count))