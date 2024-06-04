#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n, a, b;
    cin >> n;
    
    a = 1, b = 0; // False, True
    for (int i = 2; i <= n; i++){
        int t = a + b;
        b = a;
        a = t;
        b %= 10, a %= 10;
    }
    
    cout << (a + b) % 10;
    return 0;
}
