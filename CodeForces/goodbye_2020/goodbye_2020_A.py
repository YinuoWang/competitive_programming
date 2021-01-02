cases = int(input())

ans_list = []
for c in range(cases):
    n = int(input())
    x_coords = list(map(int, input().split(' ')))
    area_set = set()
    for i in range(n):
        for j in range(i+1, n):
            area_set.add(x_coords[j]-x_coords[i])
    
    ans_list.append(len(area_set))
    
for val in ans_list:
    print(val)