#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 105;
int n, l, res;
int arr[MAXN][MAXN], arr2[MAXN][MAXN];

void solved(int arr[MAXN][MAXN]){
    for (int i = 1; i <= n; i++){
        bool slope[MAXN];
        bool pos = true;
        memset(slope, false, sizeof(slope));
        for (int j = 1; j < n; j++){
            if (arr[i][j] == arr[i][j + 1]) continue;
            else if (arr[i][j] == arr[i][j + 1] + 1){
                if (j + l <= n){
                    for (int k = 2; k <= l; k++)
                        if (arr[i][j + 1] != arr[i][j + k]){
                            pos = false;
                            break;
                        }
                }
                else{
                    pos = false;
                    break;
                }
                if (pos){
                    slope[j + l] = true;
                    j = j + l - 1;
                }
            }
            else if (arr[i][j] + 1 == arr[i][j + 1]){
                if (j - l >= 0){
                    for (int k = 0; k <= l - 1; k++){
                        if (arr[i][j] != arr[i][j - k] || slope[j - k]){ // 이 문제의 핵심 slope
                            pos = false;
                            break;
                        }
                    }
                }
                else{
                    pos = false;
                    break;
                }
            }
            else {
                pos = false; 
                break;
            }
        }
        if (pos) res++;
    }
}

int main(){
    FASTIO;
    
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> arr[i][j];
            arr2[j][i] = arr[i][j];
        }
    
    solved(arr);
    solved(arr2);
    
    cout << res;
    return 0;
}
