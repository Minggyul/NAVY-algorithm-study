#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 1000001;
int n;
ll res, tree[4*MAXN];

ll query(int start, int end, int node, int left, int right){
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, 2 * node, left, right) + query(mid + 1, end, 2 * node + 1, left, right);
}

void update(int start, int end, int node, int index){
    if (index < start || index > end) return ;
    if (start == end){
        tree[node] ++;
        return ;
    }
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, index);
    update(mid + 1, end, 2 * node + 1, index);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main(){
    FASTIO;
    
    cin >> n;
    map<int, int> m;
    for (int i = 1; i <= n; i++){
        int num; cin >> num;
        m[num] = i;
    }
    
    for (int i = 0; i < n; i++){
        int num; cin >> num;
        res += query(1, n, 1, m[num], n);
        update(1, n, 1, m[num]);
        //cout << i << ' ' << res << '\n';
    }
    cout << res;
    return 0;
}
