#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int distanceArr[1000][1000];
int ground[1000][1000];
bool check[1000][1000];

pair<int, int> findTargetLocation(int n, int m) {
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(ground[y][x] == 2) return make_pair(x, y);
        }
    }
    return make_pair(0, 0);
}

void printDistanceArr(int n, int m) {
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            cout << distanceArr[y][x] << " ";
        }
        cout << endl;
    }
}

void findBlockingGround(int n, int m) {
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(ground[y][x] == 1) distanceArr[y][x] = -1;
        }
    }
}

void findShortestPath(int n, int m) {
    queue<pair<int, int>> queue;
    pair<int, int> target = findTargetLocation(n, m);
    check[target.second][target.first] = true;
    distanceArr[target.second][target.first] = 0;
    queue.push(target);

    while(!queue.empty()) {
        pair<int, int> loc = queue.front();
        queue.pop();

        for(int i = 0; i < 4; i++) {
            int x = loc.first + dx[i];
            int y = loc.second + dy[i];

            if(x < 0 || x >= m || y < 0 || y >= n || check[y][x] || ground[y][x] == 0) continue;
            check[y][x] = true;
            ground[y][x] = 3; // 갈 수 있는 길 3으로 표시
            distanceArr[y][x] = distanceArr[loc.second][loc.first] + 1;
            queue.push(make_pair(x, y));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ground[i][j];
        }
    }

    findShortestPath(n, m);
    findBlockingGround(n, m);
    printDistanceArr(n, m);
        
    return 0;
}
