#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 105;
int n, l, res;
int a[MAXN][MAXN], b[MAXN][MAXN];

void solved(int arr[MAXN][MAXN], int i, int j, int cnt){
    if (j == n) {
        res++;
        return;
    }
    
    int cur = arr[i][j];
    int next = arr[i][j + 1];
    
    if (cur == next) solved(arr, i, j + 1, cnt + 1);
    else if (cur + 1 == next){
        if (cnt >= l) solved(arr, i, j + 1, 1);
        else return;
    }
    else if (cur == next + 1){
        bool flag = true;
        if (j + l <= n){
            for (int k = j + 2; k <= j + l; k++){
                if (arr[i][k] != next) {
                    flag = false;
                    break;
                }
            }
            if (flag) solved(arr, i, j + l, 0);
            else return ;
        }
    }
}

int main(){
    FASTIO;
    
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    
    for(int i = 1; i <= n; i++) {
        solved(a, i, 1, 1);
        solved(b, i, 1, 1);
    }
    
    cout << res;
    return 0;
}
