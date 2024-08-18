#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 10005;
int a[MAXN];

int main() {
    FASTIO;
    
    ll n, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    
    for (int i = 0; i < n; i++){
        int t = -a[i];
        int l = i + 1, r = n - 1;
        while(l < r){
            int tmp = a[l] + a[r];
            if (tmp == t) {
                if (a[l] == a[r]){
                    res += (r - l + 1) * (r - l) / 2;
                    break;
                }
                else {
                    int left = 1, right = 1;
                    while(l + 1 < r && a[l] == a[l + 1]) {l++; left++;}
                    while(r - 1 > l && a[r - 1] == a[r]) {r--; right++;}
                    res += left * right;
                    l++; r--;
                }
            }
            else if (tmp < t) l++;
            else r--;
        }
    }
    
    cout << res;
    return 0;
}
/* 3151: 합이 0
하나의 수를 선택하고 나머지는 오른쪽에서 투 포인터를 돌리면 된다고 느꼈는데
이분탐색이랑 다르게 중복처리를 할 때 좀 애를 먹었다.
1) 같을 때: nC2
2) 다를 때: left * right

*/
