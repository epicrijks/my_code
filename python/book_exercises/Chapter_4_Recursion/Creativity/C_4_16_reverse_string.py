def reverse_string(s):
    return reverse_string_recur(s, 0, len(s)-1)

def reverse_string_recur(s, low, high):
    if low >= high:
        return
    else:
        return str(s[0:low]) + str(reverse_string_recur(s[low+1:high-1], low+1, high-1)) + str(s[high:len(s)])


print(reverse_string("prince"))