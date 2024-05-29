#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
bool arr[MAX];

int main(){
    FASTIO;
    
    int n, t, s, num;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> t;
    
    while(t--){
        cin >> s >> num;
        if (s == 1) {
            for (int i = num; i <= n; i += num) arr[i] = !arr[i];
        }
        else {
            for (int i = 0; num - i > 0 && num + i <= n; i ++){
                if (arr[num - i] == arr[num + i])
                    arr[num - i] = arr[num + i] = !arr[num + i];
                else
                    break;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
    return 0;
}
