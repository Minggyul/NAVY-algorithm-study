#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
ll n, m;
vector<ll> v;

bool Check(ll mid){
    ll tmp = 0;
    for (int i = 0; i < n; i++){
        tmp += mid / v[i];
        if (tmp >= m) return true;
    }
    return false;
}

int main(){
    FASTIO;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++){
	    ll num; cin >> num;
	    v.push_back(num);
	}
	
    ll lo = 0, hi = *min_element(v.begin(), v.end()) * m;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if (Check(mid)) hi = mid;
        else lo = mid;
    }
    
    cout << hi;
	return 0;
}

/* 3079: 입국심사 (G5) (+)
1. 심사에 걸리는 시간을 변수로 잡음
-> 1 <= t <= max(tk) * n
2. F -> T 배열
-> Check(mid) True -> hi = mid -> mid
3. Check 함수는 tmp += mid / v[i] -> tmp >= m

- overflow -> m이상이면 return, end = min_element * m
*/
