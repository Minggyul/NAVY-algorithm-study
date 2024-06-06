#include <iostream>

using namespace std;

int arr[100001];

/*
  이 문제는 DP가 아닌 구현으로 풀었다.
*/

int main() {
    int input;
    cin >> input;
    for(int i = 0; i < input; i++) cin >> arr[i];

    // 수열의 길이는 최소 1이다.
    int maxInc = 1; int maxDec = 1;
    int incCount = 1; int decCount = 1;
    for(int i = 0; i < input - 1; i++) {
        // 다음 인덱스의 값이 더 크거나 작거나 같을 때 길이를 1씩 추가하고, 아닐 경우 다시 길이를 1로 초기화한다.
        if(arr[i] <= arr[i + 1]) incCount++; else incCount = 1;
        if(arr[i] >= arr[i + 1]) decCount++; else decCount = 1;

        // 삼항 연산자를 이용해 최대길이를 구한다.
        maxInc = maxInc < incCount ? incCount : maxInc;
        maxDec = maxDec < decCount ? decCount : maxDec;
    }

    // 증가 수열과 감소 수열 두 수열의 길이 중 긴 수열 길이를 출력한다.
    cout << (maxInc < maxDec ? maxDec : maxInc);
}
