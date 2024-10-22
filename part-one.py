def palindrome_check(str):
    # We make our letters lowercase.
    str = str.lower()
    newstr = ''
    for char in str:
        # we check if our char is alphanumeric
        if char.isalnum():
            newstr += char
    return newstr == newstr[::-1] #we reverse the word

initial_str = "racecar"
print(palindrome_check(initial_str))
