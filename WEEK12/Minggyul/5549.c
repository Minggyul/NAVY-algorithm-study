#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 1005;
char arr[MAXN][MAXN];
int sum[3][MAXN][MAXN]; // JOI

void cal(int i, int j){
    if (arr[i][j] == 'J') sum[0][i][j] ++;
    else if (arr[i][j] == 'O') sum[1][i][j] ++;
    else sum[2][i][j] ++;
}

int main() {
    FASTIO;
    
    int m, n, q;
    cin >> m >> n >> q;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= m; i++){
        for (int k = 0; k < 3; k++)
            sum[k][i][1] += sum[k][i - 1][1];
        cal(i, 1);
    }
    for (int j = 2; j <= n; j++){
        for (int k = 0; k < 3; k++)
            sum[k][1][j] += sum[k][1][j - 1];
        cal(1, j);
    }
    
    for (int i = 2; i <= m; i++){
        for (int j = 2; j <= n; j++){
            for (int k = 0; k < 3; k++){
                sum[k][i][j] = sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
            }
            cal(i, j);
        }
    }
    for (int i = 0; i < q; i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for (int k = 0; k < 3; k++){
            cout << sum[k][ex][ey] - sum[k][ex][sy - 1] - sum[k][sx - 1][ey] + sum[k][sx - 1][sy - 1] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
