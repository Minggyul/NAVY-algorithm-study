#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = (1 << 22);
int k, h, res;
int w[MAXN], dp[MAXN];

void dfs(int cur){
    if (cur > h) return;
    
    int left = 2 * cur + 1;
    int right = 2 * cur + 2;
    dfs(left);
    dfs(right);
    
    dp[cur] = max(dp[left] + w[left], dp[right] + w[right]);
    res += abs(dp[left] - dp[right] + w[left] - w[right]);
}

int main(){
    FASTIO;
    
    cin >> k;
    h = (1 << (k + 1)) - 2;
    for (int i = 1; i <= h; i++) {
        cin >> w[i];
        res += w[i];
    }
    
    dfs(0);
    cout << res;
    return 0;
}
