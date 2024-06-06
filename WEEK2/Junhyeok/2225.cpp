#include <iostream>

using namespace std;

int dp[201][201];

/*
	합분해는 0~N 까지의 합을 K번을 더해서 N을 만들면 되는 문제이다.
 	작성한 알고리즘 같은 경우엔 분할 정복을 사용해 식을 잘게잘게 만들어 거꾸로 계산하게 만들었다.
  	중복되는 연산을 방지하기 위해 Memoization을 활용한다.
*/

int getCount(int n, int k) {
	// k == 1 일 경우 경우의 수는 N 단 하나 뿐이다.
    if(k == 1) return 1;
	// 이전에 계산한 값이 있다면 메모리에서 가져온다.
    if(dp[n][k] != 0) return dp[n][k];

    int sum = 0;
	// 완전 탐색을 이용해 모든 경우를 계산해본다.
    for(int i = 0; i <= n; i++) {
		// N에서 i만큼 뺀 값의 식을 세운다.
        sum += getCount(n - i, k - 1);
        sum %= 1000000000;
    }

    return dp[n][k] = sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getCount(n, k);
    return 0;
}
