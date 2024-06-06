#include <iostream>

using namespace std;

int cache[10000001];

int main() {
    int number;
    cin >> number;

    // 악수 점화식을 세워보면 피보나치 수열이 나온다.
    cache[1] = 1;
    cache[2] = 2;
    for(int i = 3; i <= number; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 10; // Fibo[N] = Fibo[N-1] + Fibo[N-2] (단, N >= 2)
    }
    cout << cache[number];
}
