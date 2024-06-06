#include <iostream>
#include <algorithm>
#include "string.h"

using namespace std;

int n;
int connectedWire[100];
int dp[100];

/*
  이 문제는 LIS(Longest Increasing Sub-Sequence)의 응용 문제이다.
  서로 교차되지 않는 선은 연결된 번호가 점점 증가되는 형태로 구성되면 교차되지 않는다.
  이때 점점 증가하지 않고 중간에 그 전보다 작은 숫자에 선이 연결되면 이보다 큰 숫자와 연결된 선과는 모두 교차된다.'
  그러므로 선들을 한 배열에 나열하여 LIS를 구한 후, (모든 선의 개수 - LIS 길이) = 최소치의 제거 선 개수가 된다.

int solution(int start) {
    if(dp[start] != 0) return dp[start];

    dp[start] = 1;
    for(int next = start + 1; next < n; next++) {
        if(connectedWire[start] < connectedWire[next]) {
            dp[start] = max(dp[start], solution(next) + 1);
        }
    }

    return dp[start];
}

int main() {
    cin >> n;

    int wire[501];
    // 쓰레기 값이 넣어져서 memset으로 모든 값을 -1로 초기화
    memset(wire, -1, sizeof(int) * 501);
    for(int i = 0; i < n; i++) {
        int startNumber, connectedNumber;
        cin >> startNumber >> connectedNumber;
        wire[startNumber] = connectedNumber;
    }

    int number = 0;
    // 연결된 선을 하나의 배열에 나열한다.
    for(int i = 1; i < 501; i++) {
        if(wire[i] != -1) connectedWire[number++] = wire[i];
    }

    int m = 1;
    for(int start = 0; start < n; start++) {
        m = max(m, solution(start));
    }

    cout << n - m;
    
    return 0;
}
