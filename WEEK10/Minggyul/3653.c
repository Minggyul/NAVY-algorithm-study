#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
vector<int> tree, arr;

ll query(int start, int end, int node, int left, int right){
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return query(start, mid, 2 * node, left, right) + query(mid + 1, end, 2 * node + 1, left, right);
}

void update(int start, int end, int node, int index, ll diff){
    if (index < start || index > end) return ;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, index, diff);
    update(mid + 1, end, 2 * node + 1, index, diff);
}

int main(){
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        int n, m, idx;
        cin >> n >> m;
        arr.resize(n + 1);
        tree.resize(4 * (n + m + 1));
        fill(tree.begin(), tree.end(), 0);
        
        for (int i = 1; i <= n; i++){
            arr[i] = m + i;
            update(1, n + m, 1, arr[i], 1);
        }
        
        idx = m;
        for (int i = 0; i < m; i++){
            int num; cin >> num;
            cout << query(1, n + m, 1, 1, arr[num] - 1) << ' ';
            update(1, n + m, 1, arr[num], -1);
            arr[num] = idx --;
            update(1, n + m, 1, idx - 1, 1);
        }
        cout << '\n';
    }
    return 0;
}
