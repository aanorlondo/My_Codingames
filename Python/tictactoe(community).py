b = ''
for i in range(3):
    b += input()
b = list(b)
for x,y,z in [(0,1,2), (3,4,5), (6,7,8), (0,3,6), (1,4,7), (2,5,8), (0,4,8), (2,4,6)]:
    if sorted([b[x], b[y], b[z]]) == ['.', 'O', 'O']:
        b[x], b[y], b[z] = 'O', 'O', 'O'
        print('{}{}{}\n{}{}{}\n{}{}{}'.format(*b))
        quit(0)
print("false")
