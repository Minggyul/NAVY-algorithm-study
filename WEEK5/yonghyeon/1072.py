x,y=map(int,input().split()) 
z=(100*y)//x 
left=0 
right=x 
ans=x 
if z>=99: 
    print(-1)
else: 
    while left<=right: 
        mid=(left+right)//2 
        if (y+mid)*100//(x+mid)>z: 
            ans=mid 
            right=mid-1 
        else: 
            left=mid+1
    print(ans)
