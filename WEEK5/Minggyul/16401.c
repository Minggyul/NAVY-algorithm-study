#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
ll m, n, s;
vector<ll> v;

bool Check(ll mid){
    ll tmp = 0;
    for (int i = 0; i < n; i++){
        tmp += v[i] / mid;
    }
    return tmp >= m;
}

int main(){
    FASTIO;
	
	cin >> m >> n;
	for (int i = 0; i < n; i++){
	    ll num; cin >> num;
	    v.push_back(num);
	    s += num;
	}
	sort(v.begin(), v.end());
	
    ll lo = 0, hi = *max_element(v.begin(), v.end()) + 1;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if (Check(mid)) lo = mid;
        else hi = mid;
    }
    
    cout << lo;
	return 0;
}

/* 16401: 과자 나눠주기 (S2) (-)
모든 조카에게 같은 길이의 막대 과자
M명의 조카, N개의 과자
막대 과자는 여러 조각으로 나눠질 수 있지만, 합칠 수는 없다.

1. 과자의 길이가 이분 탐색의 변수이다.
- 1에서 max(v)의 범위를 가진다.
2. Check는 N개의 벡터를 돌면서 갯수를 더한다.
3. T -> F 배열이니까 lo = mid로 둔다.
4. 예외 조건, 모든 조카에게 같은 길이의 막대를 줄 수 없는 경우
-  조카보다 다 더한 과자의 길이가 작으면 예외이긴 한데
이게 꼭 설정해야 되는지는 모르겠다. 
*/
