#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    int paint[500][500];
    bool check[500][500];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> paint[i][j];
        }
    }
    
    int count = 0, maxArea = 0;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(!paint[y][x] || check[y][x]) continue;
            
            int area = 1;
            queue<pair<int, int>> queue;
            queue.push(make_pair(x, y));
            check[y][x] = 1;
            count++;
                
            while(!queue.empty()) {
                pair<int, int> loc = queue.front();
                queue.pop();
                
                for(int i = 0; i < 4; i++) {
                    int cx = loc.first + dx[i];
                    int cy = loc.second + dy[i];
                        
                    if(cx < 0 || cx >= m || cy < 0 || cy >= n || check[cy][cx] || !paint[cy][cx]) continue;
                        
                    queue.push(make_pair(cx, cy));
                    check[cy][cx] = 1;
                    area++;
                }
            }
                
            maxArea = max(maxArea, area);
        }
    }
    
    cout << count << endl << maxArea;
    return 0;
}
