#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define t tuple<int, int, int>
const int MAXN = 1005;
const int INF = 123456789;
int m, n, arr[MAXN][MAXN];
int dist[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dijkstra(){
    priority_queue<t, vector<t>, greater<t>> pq; // dist, 좌표
    dist[0][0] = arr[0][0];
    pq.push({dist[0][0], 0, 0});
    
    while(!pq.empty()){
        auto [cd, cx, cy] = pq.top();
        pq.pop();
        
        if (cd != dist[cx][cy]) continue;
        
        for (int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && arr[nx][ny] != -1){
                if (dist[nx][ny] > cd + arr[nx][ny]){
                    dist[nx][ny] = cd + arr[nx][ny];
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
        }
    }
}

int main() {
    FASTIO;
    
    cin >> m >> n;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            dist[i][j] = INF;
        }
    }
    
    if (arr[0][0] == -1 || arr[m - 1][n - 1] == -1) cout << -1;
    else {
        dijkstra();
        if (dist[m - 1][n - 1] == INF) cout << -1;
        else cout << dist[m - 1][n - 1];
    }
    return 0;
}
