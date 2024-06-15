#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int ice[300][300];
bool check[300][300];

int getIceCount(int n, int m) {
    int count = 0;

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(ice[y][x] == 0 || check[y][x]) continue;

            count++;
            queue<pair<int, int>> queue;
            queue.push(make_pair(x, y));

            while(!queue.empty()) {
                pair<int, int> loc = queue.front();
                queue.pop();

                for(int i = 0; i < 4; i++) {
                    int cx = loc.first + dx[i];
                    int cy = loc.second + dy[i];

                    if(cx < 0 || cx >= m || cy < 0 || cy >= n || ice[cy][cx] == 0 || check[cy][cx]) continue;

                    queue.push(make_pair(cx, cy));
                    check[cy][cx] = 1;
                }
            }
        }
    }

    return count;
}

void meltIce(int n, int m) {
    int temp[300][300];
    /*
      temp 초기화 문제 때문에 4번 틀림
      컴파일러마다 변수 초기값이 다르므로 memset을 사용하는게 안전
    */
    memset(temp, 0, sizeof(temp));
    
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            if(ice[y][x] == 0) continue;

            int water = 0;
            for(int i = 0; i < 4; i++) {
                int cx = x + dx[i];
                int cy = y + dy[i];
                if(cx < 0 || cx >= m || cy < 0 || cy >= n || ice[cy][cx] != 0) continue;

                water++;
            }

            temp[y][x] = ice[y][x] - water;
            if(temp[y][x] < 0) temp[y][x] = 0; 
        }
    }

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < m; x++) {
            ice[y][x] = temp[y][x];
        }
    }
}

// void printIce(int n, int m) {
//     for(int y = 0; y < n; y++) {
//         for(int x = 0; x < m; x++) {
//             cout << ice[y][x] << " ";
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
            cin >> ice[i][j];
        }
    }

    int count = 0, year = 0;

    while(count < 2) {
        count = getIceCount(n, m);

        if(count == 0) {
            cout << 0;
            break;
        } else if (count >= 2) {
            cout << year;
            break;
        }

        // printIce(n, m);
        meltIce(n, m); 
        year++;
        memset(check, false, sizeof(check));
    }
    return 0;
}
