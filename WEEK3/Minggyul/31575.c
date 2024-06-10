#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
const int MAX = 305;
bool arr[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, 0};
int dy[] = {0, 1};

void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                if (arr[nx][ny] && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    bfs();
    
    if (visited[m - 1][n - 1]) cout << "Yes";
    else cout << "No";
    return 0;
}

/* 14756: 정수 a를 k로 만들기 (S3) (-)
N * M
진우 : 북서쪽 끝
거래소 : 남동쪽 끝
도시의 일부 구역은 공터 또는 도로 지나갈 수 있음 - 1
건물은 지나갈 수 없다 - 0

* 동쪽 또는 남쪽으로만 이동가능하다.
*/ 
