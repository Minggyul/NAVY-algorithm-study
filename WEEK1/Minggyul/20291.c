#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    int n; cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        int idx = s.find('.');
        string t = s.substr(idx + 1);
        if (m.find(t) != m.end()) m[t]++;
        else m[t] = 1;
    }
    
    vector<string> v;
    for (auto it : m){
        v.push_back(it.first);
    }
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << ' ' << m[v[i]] << '\n';
    }
    return 0;
}
