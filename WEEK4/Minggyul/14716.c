#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 255;
int n, m;
bool arr[MAXN][MAXN], visited[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(int x, int y){
    visited[x][y] = true;
    
    for (int i = 0; i < 8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < m && ny >= 0 && ny < n){
            if (arr[nx][ny] && !visited[nx][ny])
                dfs(nx, ny);
        }
    }
}

int main() {
    FASTIO;
    
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    int res = 0;        
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] && !visited[i][j]){
                dfs(i, j);
                res ++;
            }
        }
    }
    
    cout << res;
    return 0;
}

/* 14716: 현수막 (-)
*/
