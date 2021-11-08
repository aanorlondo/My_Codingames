from itertools import groupby

def to_ascii(text):
    #ord converts char to int ascii_value
    ascii_values = [ord(character) for character in text]
    #bin converts intx10 to binary intx2
    ascii_values = [bin(character)[2:] for character in ascii_values]
    #str converts int to string
    ascii_values = [str(character) for character in ascii_values]
    #x.join flattens a list to a string with the separator x
    return ''.join(ascii_values)

#you can replace the "input()" by any string
message = to_ascii(input())
#itertool's groupby creates a list from a string at any sequence break (ex: 0011 -> 00 11)
message = [''.join(g) for k, g in groupby(message)]
output = ''
for x in message :
    #0 for 1 and 00 for 0
    output += '0 ' if '1' in x else '00 '
    # 'str' * x --> writes 'str' x times
    output += '0' * len(x) + ' '
#rstrip = right strip = takes off useless spaces at the right side of the string 
print(output.rstrip())
