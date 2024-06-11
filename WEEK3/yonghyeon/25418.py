a = int(input())
k = int(input())
cnt = 0

while a < k:
    if k%2 == 0 and k//2 >= a:
        k //=2
    else:
        k -=1
    cnt+=1

print(cnt)
