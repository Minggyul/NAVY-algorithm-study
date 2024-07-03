#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define ll long long
int main(){
    FASTIO;
	
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	
	int res = 0;
	do{
	    int tmp = 0;
	    for(int i = 1; i < v.size(); i++)
	        tmp += abs(v[i] - v[i - 1]);
	   res = max(res, tmp);
	}while(next_permutation(v.begin(), v.end()));
	
	cout << res;
	return 0;
}

/* 10819: 차이를 최대로 (S2)
next_permtation을 이용해서 전체 순열을 탐색
-> 차이가 최대인 것을 저장
*/
