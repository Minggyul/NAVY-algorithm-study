#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 105;
int n, start;
vector<int> v[MAXN];
bool visited[MAXN];
bool flag;

void dfs(int cur){
    visited[cur] = true;
    
    for (int i = 0; i < v[cur].size(); i++){
        int next = v[cur][i];
        if (next == start) flag = true;
        if (!visited[next]) dfs(next);
    }
}

int main() {
    FASTIO;
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int num; cin >> num;
            if (num == 1) v[i].push_back(j);
        }
    }
    
    for (start = 1; start <= n; start++){
        memset(visited, false, sizeof(visited));
        flag = false;
        dfs(start);
        if (!flag) visited[start] = false;
        for (int j = 1; j <= n; j++)
            cout << visited[j] << ' ';
        cout << '\n';
    }
    return 0;
}

/* 11403: 경로 찾기 (0)
*/
