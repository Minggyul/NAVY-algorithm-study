#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 505;
int n, m, res;
bool d[MAXN][MAXN];

void floyd(){
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] && d[k][j]) d[i][j] = true;
}

int main() {
    FASTIO;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        d[a][b] = true;
    }
    floyd();
    
    for (int i = 1; i <= n; i++){
        int tmp = 0;
        for (int j = 1; j <= n; j++){
            if (d[i][j] || d[j][i]) tmp++;
        }
        if (tmp == n - 1) res ++;
    }
    cout << res;
    return 0;
}

/* 2458: 키 순서 (+)
[1] DFS
- 각 정점에 대하여 DFS를 두 번 실행한다.
- 정방향, 역방향

[2] Floyd-Warshall Algorithm
- 모든 k에 대하여 d[i][k] 와 d[k][j]가 만족하면 d[i][j]도 성립한다.
- d[i][j] 혹은 d[j][i]가 만족하면 서로 간의 대소관계가 명확하다.
*/
