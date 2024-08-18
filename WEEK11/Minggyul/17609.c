#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool check(string a){
    int sz = a.size();
    for (int i = 0; i < sz; i++)
        if (a[i] != a[sz - i - 1])
            return false;
    return true;
}

int main() {
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        string a;
        cin >> a;
        if (check(a)){
            cout << 0 << '\n';
            continue;
        }
        
        int sz = a.size();
        for (int i = 0; i < sz; i++){
            if (a[i] != a[sz - i - 1]){
                string b = a, c = a;
                b.erase(i, 1);
                c.erase(sz - i - 1, 1);
                if (check(b) || check(c)) {
                    cout << 1 << '\n';
                    break;
                }
                else {
                    cout << 2 << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}
/* 17609: 회문
1. 회문
2. 유사회문: 앞뒤로 봤을 때 다른 시점에서 제거했을 때 회문인가?
-> 앞 뒤에서 k번째는 바뀌지 않는 사실인데 이걸 지웠을 때 회문이 안되면 유사회문이 아니다.
3. 2출력
*/
