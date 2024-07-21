#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 15;
ll n, k, res, fact = 1;
ll dp[1 << MAXN][105], l[MAXN], a[MAXN];
ll p[55] = {1};
string s[MAXN]; 

ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll dfs(int visited, int now){
    if (visited == (1 << n) - 1) {
        if (now == 0) return 1;
    }
    
    ll &ret = dp[visited][now];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i = 0; i < n; i++){
        if (visited & (1 << i)) continue;
        ll next = (now * p[l[i]] + a[i]) % k;
        ret += dfs(visited | (1 << i), next);
    }
    return ret;
}

int main(){
    FASTIO;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> k;
    for (int i = 1; i <= 50; i++) p[i] = (p[i - 1] * 10) % k;
    for (int i = 0; i < n; i++) {
        fact *= (i + 1);
        l[i] = s[i].size();
        for (int j = 0; j < l[i]; j++) a[i] = (a[i] + p[l[i] - j - 1] * (s[i][j] - '0')) % k;
    }
    
    memset(dp, -1, sizeof(dp));
    res += dfs(0, 0);
    
    ll g = gcd(res, fact);
    if (res == 0) cout << "0/1";
    else if (res == fact) cout << "1/1";
    else cout << res / g << "/" << fact / g;
    return 0;
}
