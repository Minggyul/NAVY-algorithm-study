#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 25;
int n, m, x, y, k, dir;
int arr[MAXN][MAXN], state[6];
int dx[] = {0, 0, -1, 1}; // 동서북남 순서
int dy[] = {1, -1, 0, 0};

bool out_boundary(){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    return !(nx >= 0 && nx < n && ny >= 0 && ny < m);
}

void move(){
    if (dir == 0){
        int tmp = state[0];
        state[0] = state[4]; state[4] = state[2]; state[2] = state[5];
        state[5] = tmp;
    }
    else if (dir == 1){
        int tmp = state[0];
        state[0] = state[5]; state[5] = state[2]; state[2] = state[4];
        state[4] = tmp;
    }
    else if (dir == 2){
        int tmp = state[0];
        for (int i = 0; i < 3; i++)
            state[i] = state[i + 1];
        state[3] = tmp;
    }
    else {
        int tmp = state[3];
        for (int i = 3; i > 0; i--)
            state[i] = state[i - 1];
        state[0] = tmp;
    }
    x += dx[dir]; y += dy[dir];
    if (arr[x][y] == 0) arr[x][y] = state[2];
    else {
        state[2] = arr[x][y];
        arr[x][y] = 0;
    }
}

int main(){
    FASTIO;
    
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < k; i++){
        cin >> dir; dir --;
        if (out_boundary()) continue;
        move();
        
        cout << state[0] << '\n';
    }
    return 0;
}
