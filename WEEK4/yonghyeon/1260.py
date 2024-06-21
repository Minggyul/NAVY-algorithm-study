def dfs(t):
    dfs_list.append(t)   # 방문 노드
    v[t] = 1             # 표시

    for n in adj[t]:
        if not v[n]:
            dfs(n)

def bfs(c):
    queue = []

    queue.append(c)
    bfs_list.append(c)
    v[c] = 1

    while queue:
        t = queue.pop(0)
        for n in adj[t]:
            if not v[n]:    # 방문X 큐 삽입
                queue.append(n)
                bfs_list.append(n)
                v[n] = 1

n, m, start = map(int, input().split())
adj = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = map(int, input().split())
    adj[a].append(b) # 양방향
    adj[b].append(a) 

for i in range(1, n+1):
    adj[i].sort() # 오름차순

v = [0]*(n+1)
dfs_list = []
dfs(start)

v = [0]*(n+1)
bfs_list = []
bfs(start)

print(*dfs_list)
print(*bfs_list)
