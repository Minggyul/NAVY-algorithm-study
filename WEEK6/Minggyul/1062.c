#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 55;
int n, k, res;
string s[MAXN];
bool visited[26];

void Backtracking(int cnt, int idx){
    if (cnt == k){
        int tmp = 0;
        for (int i = 0; i < n; i++){
            bool flag = true;
            for (int j = 0; j < s[i].size(); j++){
                if (!visited[s[i][j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) tmp++;
        }
        res = max(res, tmp);
    }
    
    for (int i = idx; i < 26; i++){
        if (!visited[i]){
            visited[i] = true;
            Backtracking(cnt + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main(){
    FASTIO;
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> s[i];
	visited['a' - 'a'] = true;
	visited['n' - 'a'] = true;
	visited['t' - 'a'] = true;
	visited['i' - 'a'] = true;
	visited['c' - 'a'] = true;
    k -= 5;
    
    if (k >= 0) Backtracking(0, 0);
    cout << res;
	return 0;
}

/* 1062: 가르침 (-)
1. a n t i c는 항상 골라야 한다. (K >= 5)
2. 2^(K- 5)이므로 백트래킹이 가능하다.
*/ 
