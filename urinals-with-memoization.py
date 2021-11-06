import sys
from math import floor
n = int(input())

print("n :",n, file=sys.stderr)

segments = {} #for @memoization purposes 

def count(begin, end) :
    distance = end - begin
    if distance <= 3 :
        return 0
    mid = floor((begin+end)/2)
    if distance not in segments :
        segments[distance] = count(begin,mid) + count(mid,end) + 1
    return segments[distance]

best, first = 0 , 0
for i in range(floor(n/2)) :
    urinals = count(i,n) + count(0,i)
    if urinals > best :
        best = urinals
        first = i

print(best,first+1)
