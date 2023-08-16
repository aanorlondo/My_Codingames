import sys

n = int(input())

print("Urinals :",n, file=sys.stderr)

best , first = 0, 0 
for i in range (0, n//2) :
    
    print("First pos :",i+1, file=sys.stderr)

    count = 1 #at least the first guy
    for up in range(0,i-1,2) : 
        count += 1 #as long as a guy can enter the loop, you ++

    for down in range(n-1,i+1,-2) :
        count += 1 #same here, only its on the other side, you ++

    if count > best : #if you have more guys than previous best (init 1) you update your best
        best = count
        
        print("\tNew record : f:",i+1,"best:",best, file=sys.stderr)
        
        if i < first : #save only the smallest first position that laed to the best
            first = i
            
    print("\t\tbest :",count, file=sys.stderr)
    
print(best, first+1)
# To debug: print("Debug messages...", file=sys.stderr, flush=True)
