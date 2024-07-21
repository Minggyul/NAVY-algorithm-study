#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 105;
ll n, m;
ll w[MAXN], c[MAXN], DP[MAXN][MAXN*MAXN];

int main(){
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    
    DP[0][c[0]] = w[0];
    for (int i = 1; i < n; i++){
        DP[i][c[i]] = w[i];
        for (int j = 0; j < MAXN * MAXN; j++){
            if (j >= c[i]) DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - c[i]] + w[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }
    
    for (int j = 0; j < MAXN * MAXN; j++){
        if (DP[n - 1][j] >= m){
            cout << j;
            break;
        }
    }
    return 0;
}
