#include <bits/stdc++.h> 
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define INF 1e9
const int MAXN = 105;
int n, res;
int dist[MAXN][MAXN]; 
bool check[MAXN][MAXN];

void floyd(){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                if (i == j || j == k || i == k) continue;
                if (check[i][k] || check[k][j]) continue;
                if (dist[i][j] == dist[i][k] + dist[k][j]){
                    check[i][j] = true;
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    cout << -1;
                    exit(0);
                }
            }
}

int main() {
    FASTIO;
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> dist[i][j];
        }
    }
    
    floyd();
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (!check[i][j]) res += dist[i][j];
        }
    }
    cout << res;
    return 0;
}
