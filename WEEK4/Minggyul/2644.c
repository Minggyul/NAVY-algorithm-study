#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define INF 1e9
const int MAXN = 105;
int n, m, s, e;
vector<int> v[MAXN];
int dist[MAXN];

void dfs(int cur){
    for (int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];
        if(dist[next] == INF){
            dist[next] = min(dist[next], dist[cur] + 1);
            dfs(next);
        }
    }
}

int main() {
    FASTIO;
    
    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[s] = 1;
    dfs(s);
    if (dist[e] == INF) cout << -1;
    else cout << dist[e] - 1;
    return 0;
}
