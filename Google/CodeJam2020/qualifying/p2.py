cases = int(input())
for c in range(cases):
    string = input()
    output = []
    right_brackets = 0
    prev = 0
    for char in string:
        num_char = int(char)
        
        if num_char > prev:
            for i in range(num_char - prev):
                output.append('(')
            right_brackets += num_char - prev
        
        elif num_char < prev:
            for i in range(prev- num_char):
                output.append(')')
            right_brackets -= prev - num_char

        output.append(char)
        prev = num_char
    
    for i in range(right_brackets):
        output.append(')')

    print('Case #{}: {}'.format(c+1,''.join(output)))