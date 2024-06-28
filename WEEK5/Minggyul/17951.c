#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long
ll n, k, lo, hi, sum;
vector<ll> v;

bool Check(ll mid){
    ll tmp = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        tmp += v[i];
        if (tmp >= mid) {
            cnt ++;
            tmp = 0;
        }
    }
    if (cnt >= k) return true;
    else return false;
}

int main(){
    FASTIO;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
	    ll num; cin >> num;
	    v.push_back(num);
	    sum += num;
	}
	
	lo = -1;
	hi = sum / k + 1;
	while(lo + 1 < hi){
	    ll mid = (lo + hi) / 2;
	    if (Check(mid)) lo = mid;
	    else hi = mid;
	}
	
	cout << lo;
	return 0;
}

/* 17951: 흩날리는 시험지 속에서 내 평점이 느껴진거야 (G3) ()
시험지의 개수 N, 그룹의 수 K (1 <= K <= N <= 10^5)
시험지마다 맞은 문제의 개수 x
-> K개의 그룹으로 만들고 그룹합 최소가 최대가 되도록 하기

1. 이분탐색의 변수는 그룹합이다.
lo = 0, hi = 전체합 / k
2. 특정 mid에 대해서 그룹을 나눌 수 있는가를 생각해본다.
-> 시간초과 날 것같지만 해당 수에서 가장 mid에 맞게 이분탐색 드가보자
lower_bound를 해서 log(N) * N시간동안 그룹을 구성할 수 있다.
log(전체합 / k) * log(N) * N이면 시간안에 돌아갈 수도 있을거 같다.
3. 그룹을 만들면서 mid를 만들 수 없는 상황이면 False, hi = mid
그룹을 만들었다면 mid는 가능하기 때문에 True, lo = hi
그룹 만드는 것을 Check라고 둔다면 lo가 답이다.
4. T -> F 배열
5. Check(mid)
-> ll x = lower_bound(t.begin(), t.end(), mid - tmp) - t.begin();
-> if (x == t.size()) x--;
-> t.erase(t.begin() + x);

아 이 **, 지금 있는 순서대로 진행하면 되는거 였다. ㅠ
이러면 문제가 엄청 쉬워지는데.. lo ~ hi안에서 k개의 그룹을 만들면 된다.
-> 그룹은 앞에서 부터 순차적으로 보면서 mid를 넘으면 1개의 그룹이 완료되는 식으로 한다.
-> 전체 원소를 탐색했는데 그룹이 완료되지 않고, 현재 합이 mid보다 작으면 false

*/
