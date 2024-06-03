#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N,K;
int dp[300][300];
int main(void){
    cin>>N>>K;
    for(int i = 0 ; i <= N ; i++)
        dp[0][i] = 1;
    
    for(int k = 1 ; k < K ; k++){
        for(int i = 0 ; i <= N ; i++){
            for(int j = 0 ; j <= i ; j++){
                dp[k][i] += (dp[k-1][j]);
                dp[k][i]%=1000000000;
            }
        }
    }
    cout<<dp[K-1][N];
}