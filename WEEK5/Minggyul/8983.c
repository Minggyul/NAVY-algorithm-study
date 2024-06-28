#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long

int main(){
    FASTIO;
	
	ll m, n, l, res = 0;
	cin >> m >> n >> l;
	vector<ll> v(m);
	for (int i = 0; i < m; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++){
	    ll x, y;
	    cin >> x >> y;
	    if (l < y) continue;
	    
	    ll a = lower_bound(v.begin(), v.end(), x - (l - y)) - v.begin();
	    ll b = upper_bound(v.begin(), v.end(), x + (l - y)) - v.begin();
	    if (a != b) res++;
	}
	
	cout << res;
	return 0;
}

/* 8983: 사냥꾼 (G4) (-)
1. 사격대 M개를 정렬한다.
2. 모든 동물 N 마리에 대해서 이분탐색을 진행한다.
-> L < y => 불가능
-> L = y => x
-> L > y => x - (L - y) <= x' <= x + (L - y)
-> lower_bound(v.begin(), v.end(), x - (L - y))
찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 등장
-> upper_bound(v.begin(), v.end(), x + (L - y))
찾으려는 key 값을 초과하는 숫자가 배열 몇 번째에서 처음 등장
-> 두 값의 차이가 없으면 그 사이의 수가 없다고 판명 -> 불가능
*/
