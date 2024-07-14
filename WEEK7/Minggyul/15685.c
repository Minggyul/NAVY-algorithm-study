#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, x, y, d, g, res;
bool visited[105][1005];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    FASTIO;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y >> d >> g;
        string tmp = to_string(d);
        
        for (int j = 0; j < g; j++){
            int sz = tmp.size();
            for (int k = 0; k < sz; k++){
                int dir = tmp[sz - k - 1] - '0';
                dir = (dir + 1) % 4;
                tmp += to_string(dir);
            }
        }
        
        visited[x][y] = true;
        for (int j = 0; j < tmp.size(); j++){
            int dir = tmp[j] - '0';
            x += dx[dir];
            y += dy[dir];
            visited[x][y] = true;
        }
    }
    
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 1000; j++){
            if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) res++;
        }
    }
    cout << res;
    return 0;
}
