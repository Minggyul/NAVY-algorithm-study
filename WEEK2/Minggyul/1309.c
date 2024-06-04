#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
const int MOD = 9901;
int DP[MAX][2];

int main(){
    FASTIO;
    
    int n; cin >> n;
    
    DP[1][0] = 1, DP[1][1] = 2;
    for (int i = 2; i <= n; i++){
        DP[i][0] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
        DP[i][1] = (2 * DP[i - 1][0] + DP[i - 1][1]) % MOD;
    }
    
    cout << (DP[n][0] + DP[n][1]) % MOD;
    return 0;
}
