#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 55;
const int MAXH = 1005;
const int MOD = 10007;
int dp[MAXN][MAXH];
vector<int> v[MAXN];

int main() {
    FASTIO;
    
    int n, m, h;
    cin >> n >> m >> h;
    cin.ignore();
    for (int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int tmp = 0;
        v[i].push_back(tmp);
        for (int j = 0; j < s.size(); j++){
            if (s[j] == ' ') {
                v[i].push_back(tmp);
                tmp = 0;
            }
            else tmp = tmp * 10 + s[j] - '0';
        }
        v[i].push_back(tmp);
    }
    
    for (int i = 0; i < v[0].size(); i++) dp[0][v[0][i]]++;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < v[i].size(); j++){
            for (int k = 0; k <= h; k++){
                if (k - v[i][j] >= 0){
                    dp[i][k] += dp[i - 1][k - v[i][j]];
                    dp[i][k] %= MOD;
                }
            }
        }
    }
    
    cout << dp[n - 1][h] % MOD;
    return 0;
}
