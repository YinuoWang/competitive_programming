cases = int(input())

ans_list = []
for c in range(cases):
    n, k = list(map(int, input().split(' ')))
    heights = list(map(int, input().split(' ')))

    max_top = heights[0] + k
    min_top = heights[0] + k
    
    ans = "YES"
    for i in range(1,n-1):
        # check if we can connect
        # ground is too high or ground is too low
        if heights[i] >= max_top or heights[i] + k + k-1 <= min_top - k :
            ans = "NO"
            break
        max_top = min(heights[i]+k-1, max_top-1)+k
        min_top = max(heights[i], min_top-2*k+1)+k


    if ans == "YES":
        if not (min_top - k < heights[-1] + k and heights[-1] < max_top):
            ans = "NO"
    
    ans_list.append(ans)

print("\n".join(ans_list))