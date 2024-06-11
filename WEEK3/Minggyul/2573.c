#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 305;
int n, m, k, t;
int arr[MAX][MAX];
bool tmp[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m){
                if (arr[nx][ny] != 0 && !visited[nx][ny]){
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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                tmp[i][j] = true; // 0으로 영향력이 있음
                k ++;
            }
        }
    
    bool p = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] && !visited[i][j]){
                bfs(i, j);
                p = true;
                break;
            }
        }
        if (p) break;
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (p && arr[i][j] && !visited[i][j]){
                cout << 0;
                return 0;
            }
        }
    }
    
    while(true){
        t ++; memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] != 0){
                    int cnt = 0;
                    if (i - 1 >= 0 && tmp[i - 1][j]) cnt ++;
                    if (i + 1 < n && tmp[i + 1][j]) cnt ++;
                    if (j - 1 >= 0 && tmp[i][j - 1]) cnt ++;
                    if (j + 1 < m && tmp[i][j + 1]) cnt ++;
                    
                    if (arr[i][j] - cnt > 0) arr[i][j] -= cnt;
                    else {
                        arr[i][j] = 0;
                        k ++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 0 && !tmp[i][j]) tmp[i][j] = true;
        
        if (k == n * m) {
            cout << 0;
            return 0;
        }// 모든 빙하가 녹은 케이스 분리
        bool flag = false;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j]) {
                    bfs(i, j);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j] && !visited[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        
        if (!flag) break;
    }
    
    cout << t;
    return 0;
}

/* 2473: 빙산 (G4) ()
빙산 이외의 바다 : 0 
빙산의 각 부분별 높이 정보 배열

일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼
빙산은 줄어든다. 단, 각 칸은 0보다 줄 수 없다.
-> 다른 배열을 만들어야 하는가? 동시에 일어나는 일인가?

기존의 배열을 수정하기 위해서 tmp를 도입한다.
-> tmp를 계속해서 arr와 교환시키면 O(N^2)이니까 손해이다.
-> 0이 될 때만 tmp를 교체한다.

종료 pattern: 빙하가 분리 되었는가?
-> 일단, 무식하게 BFS를 완탐 돌려야 할듯?
-> 터질텐데..

반례
1. 두 덩어리 이상난 것이 입력으로 주어진다.
2. 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 0을 출력한다.
*/ 



