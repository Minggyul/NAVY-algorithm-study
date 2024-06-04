#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 100005;
int arr[MAX];

int main(){
    FASTIO;
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int a, b, res;
    a = b = res = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] <= arr[i]) a++;
        else a = 1;
        if (arr[i - 1] >= arr[i]) b++;
        else b = 1;
        res = max({res, a, b});
    }
    
    cout << res;
    return 0;
}
