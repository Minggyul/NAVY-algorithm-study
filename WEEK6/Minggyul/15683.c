#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 10;
int n, m, sz, res = 1e6;
int arr[MAXN][MAXN];
bool visited[MAXN][MAXN];
vector<pair<int, int>> cctv;
int dx[] = {-1, 0, 1, 0}; // 
int dy[] = {0, 1, 0, -1};

void solved(int x, int y, int i){
    i %= 4;
    while(true){
        x += dx[i]; y += dy[i];
        if (!(x >= 0 && x < n && y >= 0 && y < m) || arr[x][y] == 6) return;
        if (arr[x][y] == 0) visited[x][y] = true;
    }
}

void dfs(int cnt){
    if (cnt == sz) {
        int tmp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 0 && !visited[i][j]) tmp ++;
        res = min(res, tmp);
        return ;
    }
    
    int x = cctv[cnt].first;
    int y = cctv[cnt].second;
    bool tmp[MAXN][MAXN];
    
    for (int i = 0; i < 4; i++){
        memcpy(tmp, visited, sizeof(visited));
                
        if (arr[x][y] == 1) solved(x, y, i);
        else if (arr[x][y] == 2) for (int j = 1; j < 4; j += 2) solved(x, y, i + j);
        else if (arr[x][y] == 3) for (int j = 0; j < 2; j++) solved(x, y, i + j);
        else if (arr[x][y] == 4) for(int j = 0; j < 3; j++) solved(x, y, i + j);
        else for (int j = 0; j < 4; j++) solved(x, y, i + j);
        
        dfs(cnt + 1);
        memcpy(visited, tmp, sizeof(visited));
    }
}

int main(){
    FASTIO;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < m; j++){
	        cin >> arr[i][j];
	        if (arr[i][j] != 0 && arr[i][j] != 6)
	            cctv.push_back({i, j});
	    }
    
    sz = cctv.size();
    dfs(0);
    
    cout << res;
	return 0;
}
