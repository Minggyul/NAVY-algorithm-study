#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 3003003;
int arr[MAX];

int main() {
    FASTIO;
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (i < k) arr[n + i] = arr[i];
    }
    
    unordered_map<int, int> m;
    int pre = arr[1], res = 0;
    for (int i = 1; i <= k; i++) m[arr[i]]++;
    res = m.size();
    if (m.find(c) == m.end()) res++;
    for (int i = k + 1; i < n + k; i++){
        m[arr[i]]++;
        m[pre]--;
        if (m[pre] == 0) m.erase(pre);
        
        int tmp = m.size();
        if (m.find(c) == m.end()) tmp ++;
        res = max(res, tmp);
        pre = arr[i - k + 1];
    }
    
    cout << res;
    return 0;
}
/* 15961: 회전 초밥
k개를 슬라이딩 윈도우하면서 본다. O(n + k)
*/
