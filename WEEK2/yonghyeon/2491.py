n = int(input()) #횟수
li = list(map(int, input().split())) #숫자 입력
cnt = 1     #증가 감소의 최대 수열 길이 카운트
a =1        #최대길이 저장

for i in range(0,n-1):
    #증가
    if li[i]<=li[i+1]:
        cnt +=1
    else:
        cnt = 1
    if cnt > a:     #최대 길이가 a=1보다 크면 a에 cnt저장
        a = cnt

cnt = 1
for i in range(0,n-1):
    #감소
    if li[i]>=li[i+1]:
        cnt+=1
    else:
        cnt = 1
    if cnt > a:
        a = cnt

print(a)
