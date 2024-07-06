#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 20;
int l, c;
vector<char> v, s;

void Backtracking(int cnt, int idx){
    if (cnt == l){
        int vo = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') vo++;
        if (vo == 0 || l - vo < 2) return;
        for (int i = 0; i < s.size(); i++) cout <<s[i];
        cout << '\n';
    }
    
    for (int i = idx; i < c; i++){
        s.push_back(v[i]);
        Backtracking(cnt + 1, i + 1);
        s.pop_back();
    }
}

int main(){
    FASTIO;
	
	cin >> l >> c;
	for(int i = 0; i < c; i++) {
	    char inp; cin >> inp;
	    v.push_back(inp);
	}
	sort(v.begin(), v.end());
	
	Backtracking(0, 0);
	return 0;
}

/* 1759: 암호 만들기 (-)
1. 정렬 진행
2. Backtracking(cnt, idx) cnt + 1, idx + 1로 진행
3. 검증: 모음 1, 자음 2이상
*/ 
