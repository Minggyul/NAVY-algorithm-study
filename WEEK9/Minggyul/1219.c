#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 55;
const ll INF = 1e12;
ll n, m, a, b, dist[MAXN], arr[MAXN];
vector<tuple<ll,ll,ll>> edge;
vector<ll> v[MAXN];
bool visited[MAXN];

bool bfs(ll start){
    queue<ll> q;
    memset(visited, false, sizeof(visited));
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if (cur == b) return true;
        
        for (int i = 0; i < v[cur].size(); i++){
            int next = v[cur][i];
            if (!visited[next]){
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

bool Bellman_Ford(int start){
    dist[start] = -arr[start];
    for (int i = 0; i < n; i++){ // loop
        for (int j = 0; j < m; j++){ // edge
            auto [node_now, node_next, dist_now] = edge[j]; // Good
            ll dist_next = dist_now + dist[node_now] - arr[node_next];
            if (dist[node_now] != INF && dist_next < dist[node_next]){
                dist[node_next] = dist_next;
                if (i == n - 1){ // 음의 사이클을 가지는 node에 대하여 n node와 연결되는가?
                    if (bfs(node_now)) return true;
                }
            }
        }
    }
    return false;
}

int main(){
    FASTIO;
    
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++){
        ll x, y, z;
        cin >> x >> y >> z;
        edge.push_back({x, y, z});
        v[x].push_back(y);
    }
    for (int i = 0; i < n; i++) cin >> arr[i];
    fill(dist, dist + n, INF);
    if (Bellman_Ford(a)) cout << "Gee";
    else if (dist[b] == INF) cout << "gg";
    else {
        cout << -dist[b];
    }
    return 0;
}
