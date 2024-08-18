#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 1000005;
int arr[MAXN];

int main() {
    FASTIO;
    
    int x;
    while(cin >> x){
        int n; cin >> n;
        for(int i = 0; i < 7; i++) x *= 10;
        for(int i = 0; i < n; i++) cin >> arr[i];
        sort(arr, arr + n);
        
        int l = 0, r = n - 1;
        bool flag = false;
        while(l < r){
            int tmp = arr[l] + arr[r];
            if (tmp == x) {
                cout << "yes " << arr[l] << ' ' << arr[r] << '\n';
                flag = true;
                break;
            }
            else if (tmp < x) l++;
            else r--;
        }
        if (!flag) cout << "danger\n";
    }
    return 0;
}
/* 3649: 로봇 프로젝트

*/
