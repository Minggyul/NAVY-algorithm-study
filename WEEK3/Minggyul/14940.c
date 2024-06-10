#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, sx, sy;
const int MAX = 1005;
int arr[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (arr[nx][ny] != 0 && dist[nx][ny] == 0){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {sx = i; sy = j;}
        }
    
    bfs(sx, sy);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] != 0 && dist[i][j] == 0) cout << -1 << ' ';
            else if (arr[i][j] == 0) cout << 0 << ' ';
            else cout << dist[i][j] - 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/* 14940: 쉬운 최단거리 (S1) ()
모든 지점에 대해서 목표지점까지의 거리
1. 2는 목표지점이다.
2. 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치 -1
*/ 

