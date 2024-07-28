#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
#define pll pair<ll, ll>
const ll INF = LLONG_MAX / 4;
const int MAXN = 100005;
ll n, m, d, e, res = -INF;
ll arr[MAXN], dist[MAXN][2];
vector<pll> v[MAXN];

void Dijkstra(ll start, ll bit){
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});
    dist[start][bit] = 0;
    
    while(!pq.empty()){
        ll dist_now = pq.top().first;
        ll node_now = pq.top().second;
        pq.pop();
        
        if (dist_now != dist[node_now][bit]) continue;
        for (int i = 0; i < v[node_now].size(); i++){
            ll dist_next = dist_now + v[node_now][i].first;
            ll node_next = v[node_now][i].second;
            if (dist_next < dist[node_next][bit] && arr[node_now] < arr[node_next]){
                dist[node_next][bit] = dist_next;
                pq.push({dist_next, node_next});
            }
        }
    }
}

int main(){
    FASTIO;
    
    cin >> n >> m >> d >> e;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    
    for (int i = 1; i <= n; i++) dist[i][0] = dist[i][1] = INF;
    Dijkstra(1, 0);
    Dijkstra(n, 1);
    
    for (int i = 1; i <= n; i++){
        if (dist[i][0] != INF && dist[i][1] != INF)
            res = max(res, arr[i] * e - d * (dist[i][0] + dist[i][1]));
    }
    if (res == -INF) cout << "Impossible";
    else cout << res;
    return 0;
}
