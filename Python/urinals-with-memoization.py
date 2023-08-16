import sys
n = int(input())

print("So this guy goes to the toilet and he finds",n,"...urinals",file=sys.stderr)

segments = {} #for @memoization purposes 
def count(begin, end) : #yes, it will be recursive :)
    distance = end - begin 
    if distance <= 3 : return 0
    mid = (begin+end)//2
    if distance not in segments : #distances are classes of equivalence
        segments[distance] = count(begin,mid) + count(mid,end) + 1 #+1 is for the middle creating two new segments
    return segments[distance]

print("He gives some quick thoughts...",file=sys.stderr)
print("\t\"Where should I go so the guys can fit ?\"",file=sys.stderr)

best, first = 0 , 0 
for i in range(n//2) : #after the second half distance, we get a mirror ;)
    urinals = count(0,i) + count(i,n-1) + 1 # +1 to count i itself
    if n-i-1 >= 2 : urinals += 1 #the upper boundary counts
    if i > 1 : urinals += 1 #if i > 1, i is in the middle of a larger segment, we count the implicit boundary
    if urinals > best : #just to remember what brings each first position
        best = urinals
        first = i+1

print("The answer is urinal number",first+1,"! \nSo all of us",best,"dudes will cast mayhem on this place ! è_é",file=sys.stderr)
print(best,first)
