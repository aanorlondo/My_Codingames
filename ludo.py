p=3 //int(input())
t=[]
for i in range (p): 
	t.append(0)
r=0
for c in ("64658662138"): //input()
    print("Player",r+1,"plays",c)
    if (c=='6') :
        t[r]+=1
        print("\tPlayer",r+1,"total pawns on  table",t[r])
        if(t[r]==2):
            print("\tPlayer",r+1,"wins !!!!")
            quit()
    else: r=(r+1)%p 
print("No one wins")
