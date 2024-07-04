#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 10;
int k;
vector<int> v;
vector<string> res;
char op[MAXN];
bool visited[MAXN];

void backtracking(int cnt, int cur){
    if (cnt == k + 1){
        string tmp = "";
        for (int i = 0; i < v.size(); i++) tmp += to_string(v[i]);
        res.push_back(tmp);
    }
    
    if (op[cnt - 1] == '<'){
        for (int i = cur + 1; i < MAXN; i++){
            if (!visited[i]){
                visited[i] = true;
                v.push_back(i);
                backtracking(cnt + 1, i);
                v.pop_back();
                visited[i] = false;
            }            
        }
    }
    else{
        for (int i = 0; i < cur; i++){
            if (!visited[i]){
                visited[i] = true;
                v.push_back(i);
                backtracking(cnt + 1, i);
                v.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(){
    FASTIO;
	
	cin >> k;
	for (int i = 0; i < k; i++) cin >> op[i];
	
	for (int i = 0; i < MAXN; i++){
	    visited[i] = true;
	    v.push_back(i);
	    backtracking(1, i);
	    v.pop_back();
	    visited[i] = false;
	}
	
	cout << res.back() << '\n' << res[0]; 
	return 0;
}

/* 2529: 부등호 (S1) (-)
Backtracking
- 조건: 첫 수를 정하고 op 조건을 확인하면서 vector에 넣는다.
- 종결: op보다 1개 더 많으면 종결한다.
- 마지막 수가 가장 크고 첫 수가 가장 작다.
*/ 
