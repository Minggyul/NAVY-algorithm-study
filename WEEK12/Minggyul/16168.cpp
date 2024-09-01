#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 3005;
int v, e, in[MAXN], parent[MAXN];

int find(int a){
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return;
    parent[b] = a;
    return;
}

int main() {
    FASTIO;
    
    memset(parent, -1, sizeof(parent));
    cin >> v >> e;
    for (int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        in[x] ++; in[y] ++;
        merge(x, y);
    }
    
    int res = 0;
    for (int i = 1; i <= v; i++){
        if (in[i] % 2 == 1) res ++;
    }
    
    
    int k = find(1);
    for (int i = 2; i <= v; i++)
        if (find(i) != k) res = 1;
    if (res == 2 || res == 0) cout << "YES";
    else cout << "NO";
    return 0;
}
