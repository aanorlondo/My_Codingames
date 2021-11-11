l = int(input())
n = int(input())
distances = [n]
maxToLeft, maxToRight = 0, 0
for i in input().split():
    p = int(i)
    if p <= l-maxToRight-1 : maxToRight = l-p
    if p >= maxToLeft : maxToLeft = p

print(max(maxToLeft,maxToRight))
