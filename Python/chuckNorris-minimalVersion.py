from itertools import groupby
def to_ascii(text):
    return ''.join([str(bin(ord(character))[2:].zfill(7)) for character in text])
message = [''.join(g) for k, g in groupby(to_ascii(input()))]
output = ''
for x in message :
    output += '0 ' if '1' in x else '00 '
    output += '0' * len(x) + ' '
print(output.rstrip())
