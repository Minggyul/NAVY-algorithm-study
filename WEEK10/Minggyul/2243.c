#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 1000001;
int n;
ll tree[4*MAXN];

void update(int start, int end, int node, int index, ll diff){
    if (index < start || index > end) return ;
    tree[node] += diff;
    if (start == end) return ;
    int mid = (start + end) / 2;
    update(start, mid, 2 * node, index, diff);
    update(mid + 1, end, 2 * node + 1, index, diff);
}

void query(int start, int end, int node, int k){
    if (start == end){
        cout << start << '\n';
        update(1, MAXN - 1, 1, start, -1);
        return ;
    }
    
    int mid = (start + end) / 2;
    if (tree[2 * node] >= k) query(start, mid, 2 * node, k);
    else query(mid + 1, end, 2 * node + 1, k - tree[2 * node]);
}

int main(){
    FASTIO;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        int num, a, b;
        cin >> num;
        if (num == 1){
            cin >> a;
            query(1, MAXN - 1, 1, a);
        }
        else{
            cin >> a >> b;
            update(1, MAXN - 1, 1, a, b);
        }
    }
    return 0;
}
