#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int cheese[100][100];
bool check[100][100];

void removeRottenCheese(int n, int m) {
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(cheese[y][x] == 2) cheese[y][x] = 0;
        }
    }
}

int getCheeseCount(int n, int m) {
    int count = 0;
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(cheese[y][x] == 1) count++;
        }
    }

    return count;
}

void rottenCheese(int n, int m) {
    queue<pair<int, int>> queue;
    queue.push(make_pair(0, 0));
    memset(check, false, sizeof(check));
    
    while(!queue.empty()) {
        pair<int, int> loc = queue.front();
        queue.pop();

        for(int i = 0; i < 4; i++) {
            int x = loc.first + dx[i];
            int y = loc.second + dy[i];

            if(x < 0 || x >= m || y < 0 || y >= n || check[y][x]) continue;
            
            check[y][x] = true;
            if(cheese[y][x] == 1) {
                cheese[y][x] = 2;
                continue;
            }

            queue.push(make_pair(x, y));  
        }
    }
}

// void printCheese(int n, int m) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cout << cheese[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl << endl;
// }

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }

    int time = 0, cheeseCount = 0;
    int nowCheeseCount = getCheeseCount(n, m);
    while(true) {
        rottenCheese(n, m);
        // printCheese(n, m);
        removeRottenCheese(n, m);
        time++;
        
        int nextCheeseCount = getCheeseCount(n, m);
        if(nextCheeseCount == 0) break;
        nowCheeseCount = nextCheeseCount;
    }

    cout << time << endl << nowCheeseCount;
    return 0;
}
