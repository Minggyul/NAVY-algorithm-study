#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 500001;
int n, k, res = 1e9, arr[MAXN];
bool visited[MAXN][2]; // 짝수, 홀수의 도입
int cnt;
bool check(int x, int y){
    return x >= 0 && x < MAXN && !visited[x][y % 2];
}

void bfs(){
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n][0] = true;
    
    while(!q.empty()){
        int cur = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (arr[cur] != -1 && arr[cur] >= dist && (arr[cur] - dist) % 2 == 0) // 가능한 지점
            res = min(res, arr[cur]);
        
        int temp[] = {cur - 1, cur + 1, 2 * cur};
        for (int i = 0; i < 3; i++){
            if (check(temp[i], dist + 1)){
                q.push({temp[i], dist + 1});
                visited[temp[i]][(dist + 1) % 2] = true;
            }
        }
    }
    
    if (res == 1e9) cout << -1;
    else cout << res;
}

int main(){
    FASTIO;
    
    cin >> n >> k;
    memset(arr, -1, sizeof(arr));
    for (int t = 0; ; t++){
        int tmp = t * (t + 1) / 2;
        if (k + tmp > 500000) break;
        arr[k + tmp] = t;
    }
    bfs();
    return 0;
}
