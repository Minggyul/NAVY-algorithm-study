#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 10005;
int n;
int arr[MAXN], dp[MAXN][2];
vector<int> trees[MAXN];
vector<int> res[MAXN][2];
bool visited[MAXN];

void dfs(int cur){
    visited[cur] = true;
    dp[cur][1] = arr[cur];
    res[cur][1].push_back(cur);
    
    for (int i = 0; i < trees[cur].size(); i++){
        int next = trees[cur][i];
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            if (dp[next][0] > dp[next][1])
                for(auto it : res[next][0]) res[cur][0].push_back(it);
            else
                for(auto it : res[next][1]) res[cur][0].push_back(it);
            dp[cur][1] += dp[next][0];
            for (auto it : res[next][0]) res[cur][1].push_back(it);
        }
    }
}

void print(int i){
    sort(res[1][i].begin(), res[1][i].end());
    for (auto it : res[1][i]) cout << it << ' ';
}

int main(){
    FASTIO;
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        trees[u].push_back(v);
        trees[v].push_back(u);
    }
    dfs(1);
    
    cout << max(dp[1][0], dp[1][1]) << endl;
    if (dp[1][0] > dp[1][1]) print(0);
    else print(1);
    return 0;
}
