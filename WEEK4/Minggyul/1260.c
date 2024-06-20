#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 1005;
int n, m, k;
vector<int> v[MAXN];
bool visited[MAXN];

void dfs(int cur){
    visited[cur] = true;
    cout << cur << ' ';
    
    for (int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];
        if (!visited[next]) dfs(next);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        
        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            
            if (!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    FASTIO;
    
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());
        
    dfs(k);
    cout << '\n';
    
    memset(visited, false, sizeof(visited));
    bfs(k);
    return 0;
}

/* 1260: DFS와 BFS (-)
*/
