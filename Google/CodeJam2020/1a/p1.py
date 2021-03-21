cases = int(input())

def check_prefix(lst):
    for i in range(0, len(lst)-1):
        if lst[i][1] == lst[i+1][1][:len(lst[i][1])]:
            continue
        else:
            return False
    
    return True

def check_suffix(lst):
    for i in range(0, len(lst)-1):
        start_index = lst[i+1][0] - lst[i][0]
        if lst[i][1] == lst[i+1][1][start_index:]:
            continue
        else:
            return False
    
    return True
for c in range(1, cases+1):
    string_count = int(input())
    strings = []
    for i in range(string_count):
        strings.append(input())

    prefix = []
    suffix = [] 
    to_concat = []
    for s in strings:
        broken= s.split("*")
        first_word = broken[0]
        last_word = broken[len(broken)-1]
        if first_word == last_word:
            last_word = ""
        prefix.append((len(first_word), first_word))
        suffix.append((len(last_word), last_word))
        if len(broken) > 2:
            broken = broken[1:len(broken)-1]
            intermediate = "".join(broken)
            to_concat.append(intermediate.replace("*",""))

    prefix.sort()
    suffix.sort()
    if check_prefix(prefix) and check_suffix(suffix):
        prefix.reverse()
        suffix.reverse()
        check_string = prefix[0][1] + "".join(to_concat) + suffix[0][1]
        print("Case #{}: {}".format(c, check_string))
    else:
        print("Case #{}: {}".format(c, "*"))

    