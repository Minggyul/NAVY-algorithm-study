#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, a, b;
const int MAX = 505;
bool arr[MAX][MAX];
int dist[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 1;
    
    int tmp = 0;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (arr[nx][ny] && dist[nx][ny] == 0){
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        tmp ++;
        b = max(b, tmp);
    }
}

int main() {
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> arr[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (arr[i][j] && dist[i][j] == 0) {bfs(i, j); a++;}
    
    cout << a << '\n' << b;
    return 0;
}

/* 1926: 그림 (S1) ()
그림이 그려져 있을 때, 그림의 개수와 그 그림 중 가장 넓은 것의 넓이 출력
*/ 
