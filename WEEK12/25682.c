#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 2005;
char arr[MAXN][MAXN];
int sum[4][MAXN][MAXN];
int tmp[4];
// even black, even white, odd black, odd white;

void cal(int flag, int i, int j){
    if (flag) {
        if (arr[i][j] == 'B') sum[0][i][j] ++;
        else sum[1][i][j] ++;
    }
    else {
        if (arr[i][j] == 'B') sum[2][i][j] ++;
        else sum[3][i][j] ++;
    }    
}

int main() {
    FASTIO;
    
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int x = 0; x < 4; x++) {
            sum[x][i][1] = sum[x][i - 1][1];
            sum[x][1][i] = sum[x][1][i - 1];
        }
        if (i % 2 == 1) {
            cal(true, i, 1);
            cal(true, 1, i);
        }
        else {
            cal(false, i, 1);
            cal(false, 1, i);
        }
    }
    
    for (int i = 2; i <= n; i++){
        for (int j = 2; j <= m; j++){
            for (int x = 0; x < 4; x++){
                sum[x][i][j] = sum[x][i - 1][j] + sum[x][i][j - 1] - sum[x][i - 1][j - 1];            
            }
            if ((i + j) % 2 == 0) cal(true, i, j);
            else cal(false, i, j);
        }
    }
    
    int res = INT_MAX;
    for (int i = 1; i + k - 1 <= n; i++){
        for (int j = 1; j + k - 1 <= m; j++){
            // (i, j) -> (i + k - 1, j + k - 1)
            for (int x = 0; x < 4; x++){
                tmp[x] = sum[x][i + k - 1][j + k - 1] - sum[x][i - 1][j + k - 1] - sum[x][i + k - 1][j - 1] + sum[x][i - 1][j - 1];
            }
            int a = max(tmp[0] + tmp[3], tmp[1] + tmp[2]);
            res = min(res, k * k - a);
        }
    }
    cout << res;
    return 0;
}
