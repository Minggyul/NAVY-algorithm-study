#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 35;
bool DP[MAXN][40005]; // 개수, 무게
int arr[MAXN];

int main(){
    FASTIO;
    
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    DP[0][arr[0]] = true;
    for (int i = 1; i < n; i++){
        DP[i][arr[i]] = true;
        for (int j = 1; j <= 40000; j++){
            if (DP[i - 1][j]) DP[i][j] = true;
            else if (DP[i - 1][abs(j - arr[i])]) DP[i][j] = true;
            else if (DP[i - 1][j + arr[i]]) DP[i][j] = true;
        }
    }
    
    cin >> m;
    for (int i = 0; i < m; i++){
        int num; cin >> num;
        if (DP[n - 1][num]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}
