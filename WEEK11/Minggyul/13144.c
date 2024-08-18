#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
const int MAXN = 100005;
ll arr[MAXN];
bool p[MAXN];

int main() {
    FASTIO;
    
    ll n, res = 0;
    cin >> n;
    for (ll i = 0; i < n; i++) cin >> arr[i];
    
    ll s = 0;
    for (ll e = 0; e < n; e++){
        while(p[arr[e]]){
            p[arr[s]] = false;
            s ++;
            res += e - s;
        }
        res ++;
        p[arr[e]] = true;
        if (e == n - 1) res += (e - s) * (e - s + 1) / 2;
    }
    
    cout << res;
    return 0;
}
/* 13144: List of Unique Number 5 1 2 2 2 1이 반레였다.
반례를 보고 틀렸다는 것을 깨달아서
left와 right로 가면서 연속이 아닌 것을 찾으면 될듯

1 2 2 2 1
1
1 2
2를 만났는데 2가 있다.
-> s부터 삭제하면서 뒤로 밀기
-> e - s만큼 계속 증가시켜야함 (1삭제했을 때 s = 1, e = 2인데 e - s = 1 이건 2가 된다는 뜻)

*/
