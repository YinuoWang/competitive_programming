s = input()
ans = "Yes"
for i, char in enumerate(s):
    if (i % 2 == 0 and char != char.lower()) or (i % 2 == 1 and char != char.upper()):
        ans = "No"
        break

print(ans)