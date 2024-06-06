#include <iostream>
#include <algorithm>

using namespace std;

int n;
int box[1000];
int dp[1000];

/*
  상자넣기 문제는 LIS(Longest Increasing Sub-Sequence) 알고리즘과 동일하다.
  즉, 최장 증가 부분 수열을 구하면 된다.
*/
int solution(int start) {
    if(dp[start] != 0) return dp[start];

    dp[start] = 1;
    for(int next = start + 1; next < n; next++) {
        if(box[start] < box[next]) {
            // 부분 수열 중 가장 긴 부분의 길이를 저장한다.
            dp[start] = max(dp[start], solution(next) + 1);
        }
    }

    return dp[start];
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> box[i];
    }

    int m = 1;
    // 모든 구간에서 시작점을 잡아 구한다.
    for(int i = 0; i < n; i++) {
        m = max(m, solution(i));
    }
    
    cout << m;
    return 0;
}
