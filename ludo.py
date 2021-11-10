p=int(input())
t=[0,0]
r=1
for c in zip(input()) :
    if(c=='6'):
        t[r-1]+=1
        if(t[r-1]==2):
            print(r) 
    else:r+=1%r
print(0)
