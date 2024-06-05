#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAX = 5001;
const int MOD = 1e9;
ll DP[MAX];

int main(){
    FASTIO;
    
    ll n, k;
    cin >> n >> k;
    
    for (int i = 1; i <= n + k - 1; i++){
        for (int j = n; j >= 0; j--){
            if (j == 0 || j == i) DP[j] = 1;
            else DP[j] = (DP[j - 1] + DP[j]) % MOD;
        }
    }
    
    cout << DP[n] % MOD;
    return 0;
}

/*
# 1
DP[i][j] = DP[i][0] + DP[i][1] + .... + DP[i][j - 1]
DP[i - 1][j] = DP[i][0] + DP[i][1] + ... + DP[i - 1][j - 1]

DP[i][j] = DP[i - 1][j] + DP[i][j  - 1] 이 성립한다.

# 2 중복조합
n + 1 H k - 1 = n + k - 1 C n
파스칼의 삼각형, DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
발전, DP[j] = (DP[j - 1] + DP[j]) % MOD;
더 나아가, 중국인의 나머지 정리 혹은 뤼카의 정리를 통해서 구할 수 있음
*/
