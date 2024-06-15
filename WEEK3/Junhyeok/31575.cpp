#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dy[2] = {1, 0};
int dx[2] = {0, 1};

int main() {
    int n, m;
    int city[300][300];
    int check[300][300];
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }
    
    if(n == 1 && m == 1) {
        cout << "Yes";
        return 0;
    }
    
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    while(!queue.empty()) {
        pair<int, int> loc = queue.front();
        queue.pop();
        
        for(int i = 0; i < 2; i++) {
            int x = loc.first + dx[i];
            int y = loc.second + dy[i];
            
            if(x >= n || y >= m || check[y][x]) continue; 
            
            if(x == n -1 && y == m - 1) {
                cout << "Yes";
                return 0;
            }
            
            if(city[y][x]) {
                queue.push(make_pair(x, y));
                check[y][x] = 1;
            }
        }
    }
    
    cout << "No";
    return 0;
}
