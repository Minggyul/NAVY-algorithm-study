#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 105;
int DP[MAX];

int main(){
    FASTIO;
    
    int n; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    
    int res = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++)
            if (v[i].second < v[j].second && DP[i] == DP[j]) DP[j] ++; 
        res = max(res, DP[i]);
    }
    
    cout << n - res - 1;
    return 0;
}

/*
1. A 정렬
2. B는 A가 증가하기 때문에 감소한다면 역방향이 생김
3. B의 가장 긴 증가하는 부분 수열을 구함
arr[i] < arr[j] && DP[i] == DP[j] 
i가 j보다 작으면서 DP가 같다는 말은 i는 j가 선택한 모든 수들에 대해서 가지고 있다.
*/ 
