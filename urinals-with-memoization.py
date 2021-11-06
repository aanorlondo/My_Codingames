import sys
n = int(input())
print("So this guy goes to the toilet and he finds",n,"...urinals",file=sys.stderr)
segments = {} #for @memoization purposes 

def count(begin, end) : #yes, it will be recursive :)
    distance = end - begin 
    if distance <= 3 :
        return 0
    mid = (begin+end)//2
    if distance not in segments : #distances are classes of equivalence (5-2 = 3-0 = 4-1, etc.)
        segments[distance] = count(begin,mid) + count(mid,end) + 1 #+1 is for the middle creating 2 new segments
    return segments[distance]

print("He gives some quick thoughts...",file=sys.stderr)
print("\t\"Where should I go so the guys can fit ?\"",file=sys.stderr)

best, first = 0 , 0 
for i in range(n//2) : #after the second half distance, we get a mirror ;)
    urinals = count(0,i) + count(i,n-1)
    if i > 1 : urinals += 3 #if i > 1, i is a middle, meaning that we have already 2 native segments and we need to count their boundaries
    else : urinals += 2 #owise, the first segment [0-i] can't receive a guy at position 0, so it doesn't count :)
    if urinals > best : #just to remember what brings each first position
        best = urinals
        first = i

print("The answer is urinal number",first+1,"! \nSo all of us",best,"dudes will cast mayhem on this place ! è_é",file=sys.stderr)
print(best,first+1)
