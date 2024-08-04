#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 100005;
ll res = LLONG_MIN / 2, dp[MAXN], tree[4 * MAXN];

ll query(int start, int end, int node, int left, int right){
    if (left > end || right < start) return LLONG_MIN / 2;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return max(query(start, mid, 2 * node, left, right), query(mid + 1, end, 2 * node + 1, left, right));
}

void update(int start, int end, int node, int index, ll diff){
    if (index < start || index > end) return ;
    if (start == end) {
        tree[node] = diff;
        return ;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, index, diff);
    update(mid + 1, end, 2 * node + 1, index, diff);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main(){
    FASTIO;
    
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> dp[i];
    for (int i = 1; i <= n; i++){
        dp[i] = max(dp[i], dp[i] + query(1, n, 1, max(1, i - d), i - 1));
        update(1, n, 1, i, dp[i]);
        res = max(res, dp[i]);
    }
    
    cout << res;
    return 0;
}
