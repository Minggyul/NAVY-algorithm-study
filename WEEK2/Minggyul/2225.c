#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 201;
ll DP[MAX][MAX], MOD = 1e9;

int main(){
    FASTIO;

    ll N, K;
    cin >> N >> K;
    
    for (int i = 1; i < MAX; i++) DP[0][i] = 1;
    for (int i = 1; i < MAX; i++){
        DP[i][1] = 1;
        for (int j = 2; j < MAX; j++){
            for (int k = 0; k <= i; k++){
                DP[i][j] = (DP[i][j] + DP[k][j - 1]) % MOD;
            }
        }
    }
    
    cout << DP[N][K] % MOD;
    return 0;
}

/*
1. 0을 고려해야 한다.
2. 전체 범위를 고려하는게 편하다.

사실 점화식은 간단한데, DP[i][j] : i를 j개의 수로 만드는 경우의수
DP[i][j] = DP[k][j - 1] (0 <= k <= i)이다. 
*/
