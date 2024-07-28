#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 105;
int n, m, dp[MAXN][MAXN], check[MAXN], in[MAXN]; 
vector<pair<int, int>> edge[MAXN];

void Tolpology_Sort(){
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0) {
            q.push(i);
            dp[i][i] = 1;
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (int j = 0; j < edge[cur].size(); j++){
            int next = edge[cur][j].first;
            int w = edge[cur][j].second;
            for (int k = 1; k <= n; k++)
                dp[next][k] += dp[cur][k] * w;
            if (--in[next] == 0)
                q.push(next);
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (!check[i]) cout << i << ' ' << dp[n][i] << '\n';
    }
}

int main(){
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, k;
        cin >> x >> y >> k;
        edge[y].push_back({x, k});
        in[x] ++;
        check[x] = true;
    }
    Tolpology_Sort();
    return 0;
}
