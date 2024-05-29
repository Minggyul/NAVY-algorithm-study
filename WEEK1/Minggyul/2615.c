#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 19;
int arr[MAX][MAX];

int main(){
    FASTIO;
    
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cin >> arr[i][j];
        }
    }
    
    // 가로 검증
    for (int i = 0; i < MAX; i++){
        for (int j = 0; j <= MAX - 5; j++){
            if (!arr[i][j]) continue;
            bool flag = true;
            for (int k = 0; k < 5; k++){
                if (arr[i][j] != arr[i][j + k]) {
                    flag = false;
                    break;
                }
            }
            if (j != MAX - 5 && arr[i][j] == arr[i][j + 5]) flag = false;
            if (j != 0 && arr[i][j] == arr[i][j - 1]) flag = false;
            if (flag) {
                cout << arr[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    
    // 세로 검증
    for (int i = 0; i <= MAX - 5; i++){
        for (int j = 0; j < MAX; j++){
            if (!arr[i][j]) continue;
            bool flag = true;
            for (int k = 0; k < 5; k++){
                if (arr[i][j] != arr[i + k][j]) {
                    flag = false;
                    break;
                }
            }
            if (i != MAX - 5 && arr[i][j] == arr[i + 5][j]) flag = false;
            if (i != 0 && arr[i][j] == arr[i - 1][j]) flag = false;
            if (flag) {
                cout << arr[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    
    // 오른쪽 아래 대각선
    for (int i = 0; i <= MAX - 5; i++){
        for (int j = 0; j <= MAX - 5; j++){
            if (!arr[i][j]) continue;
            bool flag = true;
            for (int k = 0; k < 5; k++){
                if (arr[i][j] != arr[i + k][j + k]) {
                    flag = false;
                    break;
                }
            }
            if (i != MAX - 5 && j != MAX - 5 && arr[i][j] == arr[i + 5][j + 5]) flag = false;
            if (i != 0 && j != 0 && arr[i][j] == arr[i - 1][j - 1]) flag = false;
            if (flag) {
                cout << arr[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }    
    
    // 왼쪽 아래 대각선
    for (int i = MAX - 1; i >= 4; i--){
        for (int j = 0; j <= MAX - 5; j++){
            if (!arr[i][j]) continue;
            bool flag = true;
            for (int k = 0; k < 5; k++){
                if (arr[i][j] != arr[i - k][j + k]) {
                    flag = false;
                    break;
                }
            }
            if (i != 4 && j != MAX - 5 && arr[i][j] == arr[i - 5][j + 5]) flag = false;
            if (i != MAX - 1 && j != 0 && arr[i][j] == arr[i + 1][j - 1]) flag = false;
            if (flag) {
                cout << arr[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }    
    
    cout << 0;
    return 0;
}

// 배열을 다 처리하고, 맨 마지막 뿐아니라 앞에도 없어야함
// 가장 왼쪽에 있는 바둑알을 출력해야한다. 그 중에서도 위
// 즉, 아래 대각선은 반대로 생각할 것
