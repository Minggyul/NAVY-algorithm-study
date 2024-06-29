m, n = map(int, input().split())
l = list(map(int, input().split()))

start = 1
end = max(l)
ans = 0

while start <= end:
    mid = (start + end)//2
    cnt = 0
    for i in l:
        cnt += i // mid
    if cnt >= m:
        ans = mid
        start = mid + 1
    else:
        end = mid - 1

print(ans)
