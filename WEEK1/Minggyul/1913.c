#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
int arr[MAX][MAX];

int main(){
    FASTIO;
    
    int n, k, sx, sy, tx, ty, res = 1;
    cin >> n >> k;
    sx = sy = n / 2;
    arr[sx][sy] = res++;
    
    while(sx != 0){
        int next = sx + 2 * (n / 2 - sy) + 1;
        arr[sx - 1][sy] = res++; // 올라가기       
        for (int i = sy + 1; i <= next; i++) arr[sx - 1][i] = res ++; // 1구간
        for (int i = sx; i <= next; i++) arr[i][next] = res ++; // 2구간
        for (int i = next - 1; i >= sy - 1; i--) arr[next][i] = res ++; // 3구간
        for (int i = next - 1; i >= sx - 1; i--) arr[i][sy - 1] = res ++; // 4구간 
        sx --; sy --;
    } 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
            if (arr[i][j] == k) tx = i + 1, ty = j + 1;
        }
        cout << '\n';
    }
    cout << tx << ' ' << ty << '\n';
    return 0;
}
