import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)


dy = [ 0,1,1,1,0,-1,-1,-1]
dx = [1,1,0,-1,-1,-1,0,1]

m,n = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(m)]

def dfs(y,x):
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if 0 <= ny < m and 0 <= nx < n:
            if graph[ny][nx] == 1:
                graph[ny][nx] = 0
                dfs(ny,nx)
    return True

cnt = 0
for y in range(m):
    for x in range(n):
        if graph[y][x] == 1:
            graph[y][x] = 0
            dfs(y,x)
            cnt += 1

print(cnt)
