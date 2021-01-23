n = int(input())
false_ways, true_ways = 1, 1
for _ in range(n):
    if input() == "AND":
        false_ways = 2*false_ways + true_ways
    else:
        true_ways = false_ways + 2*true_ways

print(true_ways)