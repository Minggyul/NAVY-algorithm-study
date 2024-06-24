#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define ll long long
ll x, y;
double z;

bool Check(ll mid){
    double tmp = 1.0 * (y + mid) / (x + mid) + 1e-12;
    tmp = floor(100 * tmp);
    return tmp > z;
}

int main(){
    FASTIO;
	
	cin >> x >> y;
	z = floor(100.0 * y / x);
	if (z >= 99){
	    cout << -1;
	    return 0;
	}
	
	ll lo = 0, hi = x + 1;
	while(lo + 1 < hi){
	    ll mid = (lo + hi) / 2;
	    if (Check(mid)) hi = mid;
	    else lo = mid;
	}
	
	cout << hi;
	return 0;
}

/* 1072: 게임 (S3) (+)
게임 횟수: X
이긴 게임: Y (Z%), Z는 소수점을 버린다.
X = 53, Y = 47, Z = 88
X, Y가 주어졌을 때 게임을 최소 몇 번 더해야 Z가 변하는지

47/53 = 0.8867...
(47 + x) / (53 + x) = 0.89.... 되는 최소의 x

x의 범위를 예측해야 할듯
b / a -> (a + b) / 2a = a/2a + b/2a = 1/2 + b/2a < b / a
1 / 2 < b/2a
b > a 성립하지 않으므로, a까지만 생각하면 된다.
(단 a != b일 때만 성립)

1. overflow 조심 - double 형태
2. F -> T 배열인데 Check(mid) true이면 hi = mid로 해야함
3. Z는 소수점을 버린다.
4. 부동 소수점 문제까지..
진짜 죽으셈 제발
*/
