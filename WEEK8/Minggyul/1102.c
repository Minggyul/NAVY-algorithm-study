#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 18;
int n, p;
int DP[1 << MAXN];
int w[MAXN][MAXN];


int DFS(int visited){
    cout << "DFS (" << visited << ") 진입" << '\n';
    int &ret = DP[visited];
    if (ret != -1) return ret;
    
    if (__builtin_popcount(visited) >= p) return 0;
    
    ret = 1e9;
    for (int i = 0; i < n; i++){
        if (!(visited & (1 << i))) continue;
        for (int j = 0; j < n; j++){
            if (visited & (1 << j)) continue;
            ret = min(ret, DFS(visited | (1 << j)) + w[i][j]);
            cout << ret << '\n';
        }
    }
    cout << "DFS (" << visited << ") 탈출" << '\n';
    return ret;
}

int main(){
    FASTIO;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> w[i][j];
        }
    }
    int visited = 0;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        if (c == 'Y') visited |= (1 << i); 
    }
    cin >> p;
    
    int res = 1e9;
    memset(DP, -1, sizeof(DP));
    res = min(res, DFS(visited));
    for (int i = 0; i < (1 << n); i++)
        cout << DP[i] << ' ';
    cout << '\n';
    if (res == 1e9) cout << -1;
    else cout << res;
    return 0;
}
