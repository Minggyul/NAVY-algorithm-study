#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 40005;
const int MOD = 123456789;
bool pos[MAXN];
int dp[MAXN];

int main() {
    FASTIO;
    
    int n; cin >> n;
    for (int i = 2; i * i <= n; i++){
        if (pos[i]) continue;
        for (int j = i + i; j <= n; j += i) pos[j] = true;
    }
    
    vector<int> v;
    for (int i = 2; i <= n; i++)
        if (!pos[i])
            v.push_back(i);
            
    dp[0] = 1;
    for (int i = 0; i < v.size(); i++){
        for (int j = v[i]; j <= n; j++){
            dp[j] = (dp[j] + dp[j - v[i]]) % MOD;
        }
    }
    cout << dp[n];
    return 0;
}
