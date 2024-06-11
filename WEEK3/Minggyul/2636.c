#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
int n, m, k, t, pre;
bool arr[MAX][MAX];
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
                if (!arr[nx][ny] && !visited[nx][ny]){
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main() {
    FASTIO;
    
    // INPUT
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (!arr[i][j]) k++;
        }
    }
    
    // Simulation
    pre = n * m - k;
    while(k != n * m){
        // Intialize
        t ++;
        pre = n * m - k;
        memset(visited, false, sizeof(visited));
        
        // 0 - BFS
        bfs(0, 0);
        
        // Check O(N^2)
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (arr[i][j]){
                    for(int a = 0; a < 4; a++){
                        int ni = i + dx[a];
                        int nj = j + dy[a];
                        
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m){
                            if (visited[ni][nj]) {
                                arr[i][j] = false;
                                k ++;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << t << '\n' << pre;
    return 0;
}

/* 2473: 치즈 (G4) ()
치즈가 모두 녹아 없어지는 데 걸리는 시간
모두 녹기 한 시간 전에 남아있는 치즈조각 칸의 개수

치즈 안에 0은 효과가 없다.
-> 어떻게 구현할 것인가, BFS를 반대로 0을 중심으로 본다.
-> (0, 0)시작한 BFS가 도달하지 못한 0은 쓸모없는 0이다.
-> visited[][] = 1인 놈은 주변을 지울 수 있는 능력이 있다.
*/ 
