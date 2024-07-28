#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 255;
const int INF = 1e9;
int n, m;
int parent[MAXN], dist[MAXN][MAXN];
char arr[MAXN][MAXN];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int find(int a){
    if (parent[a] < 0) return a;
    return parent[a] = find(parent[a]);
}

bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

int bfs(int sx, int sy, int ex, int ey){
    for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, INF);
    dist[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    
    while(!q.empty()){ // 0-1
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n){
                if (arr[next_x][next_y] != '1'){
                    if (dist[next_x][next_y] > dist[cur_x][cur_y] + 1){
                        dist[next_x][next_y] = dist[cur_x][cur_y] + 1;
                        q.push({next_x, next_y});
                    }
                }
            }
        }
    }
    return dist[ex][ey];
}

int main(){
    FASTIO;
    
    vector<tuple<int, int, int>> edge;
    vector<pair<int, int>> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'S' || arr[i][j] == 'K'){
                v.push_back({i, j});
            }
        }
    }
    
    int sz = v.size();
    for (int i = 0; i < sz; i++){
        for (int j = i + 1; j < sz; j++){
            int w = bfs(v[i].first, v[i].second, v[j].first, v[j].second);
            if (w != INF)
                edge.push_back({w, i, j});
        }
    }
    sort(edge.begin(), edge.end());
    
    int res = 0, cnt = 0;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < edge.size(); i++){
        auto [w, u, v] = edge[i];
        if (merge(u, v)) {
            res += w;
            cnt ++;
        }
        if (cnt == m) break;
    }
    
    if (cnt != m) cout << -1; // 도달할 수 없는 지역이 있음
    else cout << res;
    return 0;
}
