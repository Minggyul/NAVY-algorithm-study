#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 55;
int n, m, r, c, d, res;
int arr[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool boundary(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool check(){
    for (int i = 0; i < 4; i++){
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (boundary(nr, nc) && !arr[nr][nc]) return true;
    }
    return false;
}

int main(){
    FASTIO;
    
    cin >> n >> m >> r >> c >> d;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    while(true){
        if(!arr[r][c]){
            arr[r][c] = 2;
            res ++;
        }
        
        if (check()){
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (boundary(nr, nc) && !arr[nr][nc]){
                r = nr;
                c = nc;
            }
        }
        else {
            int nr = r - dx[d];
            int nc = c - dy[d];
            if (boundary(nr, nc) && arr[nr][nc] != 1){
                r = nr;
                c = nc;
            }
            else break;
        }
    }
    return 0;
}
