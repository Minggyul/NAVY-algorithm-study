#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int n, sz, l = 0, res = 0;
    string s;
    cin >> n >> s;
    
    sz = s.size();
    unordered_map<char, int> m;
    for (int r = 0; r < sz; r++){
        m[s[r]]++;
        while(m.size() > n){
            m[s[l]]--;
            if (m[s[l]] == 0) m.erase(s[l]);
            l ++;
        }
        
        res = max(res, r - l + 1);
    }
    
    cout << res;
    return 0;
}
/* 16472: 고냥이
left를 0 기준, right를 size만큼 진행시킨다.
map에서 n개가 넘으면 left를 n개가 될 때 까지 계속 뺀다.
right - left + 1이 답으로 갱신한다.
*/
