#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1005;
int arr[MAX], DP[MAX][2];

int main(){
    FASTIO;
    
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    DP[1][1] = 1;
    for (int i = 2; i <= n; i++){
        DP[i][0] = max(DP[i - 1][0], DP[i - 1][1]);
        for (int j = 1; j < i; j++){
            if (arr[j] < arr[i]){
                DP[i][1] = max(DP[i][1], DP[j][1]);
            }
        }
        DP[i][1] ++;
    }
    
    cout << max(DP[n][0], DP[n][1]);
    return 0;
}
