#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 1000005;
const ll MOD = 1e9 + 7;
int n, m, k;
ll arr[MAXN];
ll *tree;

ll init(int start, int end, int node){
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, 2 * node) % MOD * init(mid + 1, end, 2 * node + 1) % MOD) % MOD;
}

ll multiply(int start, int end, int node, int left, int right){
    if (right < start || left > end) return 1;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return (multiply(start, mid, 2 * node, left, right) % MOD * multiply(mid + 1, end, 2 * node + 1, left, right) % MOD) % MOD;
}

void update(int start, int end, int node, int index, ll p){
    if (index < start || index > end) return ;
    if (start == end) {
        tree[node] = p;
        return ;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node , index, p);
    update(mid + 1, end, 2 * node + 1, index, p);
    tree[node] = (tree[2 * node] % MOD * tree[2 * node + 1] % MOD) % MOD;
}


int main(){
    FASTIO;
    
    cin >> n >> m >> k;
    int h = (int)ceil(log2(n));
    tree = new ll[1 << (h + 1)];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, n, 1);
    
    for (int i = 0; i < m + k; i++){
        ll num, a, b;
        cin >> num >> a >> b;
        if (num == 1){
            arr[a] = b;
            update(1, n, 1, a, b);
        }
        else{
            cout << multiply(1, n, 1, a, b) << '\n';
        }
    }
    

    return 0;
}
