#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 505;
int n, m, tmp, res;
vector<int> v[2][MAXN]; // bigger, lower
bool visited[MAXN];

void dfs(int dir, int cur){
    visited[cur] = true;
    
    for (int i = 0; i < v[dir][cur].size(); i++){
        int next = v[dir][cur][i];
        
        if (!visited[next]) {
            tmp ++;
            dfs(dir, next);
        }
    }
}

int main() {
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[0][x].push_back(y);
        v[1][y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++){
        tmp = 0;
        memset(visited, false, sizeof(visited));
        dfs(0, i);
        memset(visited, false, sizeof(visited));
        dfs(1, i);
        if (tmp == n - 1) res ++;
    }
    
    cout << res;
    return 0;
}
