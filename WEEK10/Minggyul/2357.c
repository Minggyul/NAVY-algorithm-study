#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 100005;
int n, m;
ll arr[MAXN];
ll *tree[2];

ll init(int start, int end, int node, int state){
    if (start == end) return tree[state][node] = arr[start];
    int mid = (start + end) / 2;
    if (state == 0)
        return tree[state][node] = min(init(start, mid, 2 * node, state), init(mid + 1, end, 2 * node + 1, state));
    else
        return tree[state][node] = max(init(start, mid, 2 * node, state), init(mid + 1, end, 2 * node + 1, state));
}

ll query(int start, int end, int node, int left, int right, int state){
    if (right < start || left > end) {
        if (state == 0) return INT_MAX;
        else return INT_MIN;
    }
    if (start >= left && end <= right) return tree[state][node];
    int mid = (start + end) / 2;
    if (state == 0)
        return min(query(start, mid, 2 * node, left, right, state), query(mid + 1, end, 2 * node + 1, left, right, state));
    else
        return max(query(start, mid, 2 * node, left, right, state), query(mid + 1, end, 2 * node + 1, left, right, state));
}

int main(){
    FASTIO;
    
    cin >> n >> m;
    int h = (int)ceil(log2(n));
    tree[0] = new ll[1 << (h + 1)];
    tree[1] = new ll[1 << (h + 1)];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, n, 1, 0);
    init(1, n, 1, 1);
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << query(1, n, 1, a, b, 0) << ' ' << query(1, n, 1, a, b, 1) << '\n';
    }

    return 0;
}
