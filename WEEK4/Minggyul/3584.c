#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 10005;
int parents[MAXN];

int main() {
    FASTIO;
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        memset(parents, 0, sizeof(parents));
        for (int i = 0; i < n - 1; i++){
            int x, y; cin >> x >> y;
            parents[y] = x;
        }
        
        int a, b, cur; 
        vector<int> A, B;
        cin >> a >> b;
        while(a != 0){
            A.push_back(a);
            a = parents[a];
        }
        while(b != 0){
            B.push_back(b);
            b = parents[b];
        }
        
        bool flag = false;
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < B.size(); j++){
                if (A[i] == B[j]){
                    cout << A[i] << '\n';
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
    }
    return 0;
}
