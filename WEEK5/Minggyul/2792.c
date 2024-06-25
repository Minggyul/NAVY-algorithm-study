#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
ll n, m;
vector<ll> v;

bool Check(ll mid){
    ll tmp = 0;
    for (int i = 0; i < m; i++){
        tmp += (v[i] + mid - 1) / mid;
    }
    return tmp <= n;
}

int main(){
    FASTIO;
	
	cin >> n >> m;
	for (int i = 0; i < m; i++){
	    ll num; cin >> num;
	    v.push_back(num);
	}
	
    ll lo = 0, hi = *max_element(v.begin(), v.end()) + 1;
    while(lo + 1 < hi){
        ll mid = (lo + hi) / 2;
        if (Check(mid)) hi = mid;
        else lo = mid;
    }
    
    cout << hi;
	return 0;
}

/* 2792: 보석 상자 (S1) (-)
1. 질투심을 변수로 지정
2. F -> T 배열이다.
- Check(mid) True -> hi = mid 
3. Check 함수
- vector에 대하여 tmp += (it + n - 1 / n)
- tmp <= n이면 True이다. 
*/
