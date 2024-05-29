#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    FASTIO;
    
    string s, t = "";
    getline(cin, s);
    bool flag = false;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '<') {
            flag = true;
            if (t != "") {
                cout << t;
                t = "";
            }
            t += s[i];
        }
        else if (s[i] == '>') {
            t += s[i];
            cout << t;
            t = "";
            flag = false;
        }
        else if (flag) t += s[i];
        else if (s[i] == ' ') {
            cout << t << ' ';
            t = "";
        }
        else t = s[i] + t;
    }
    if (t != "") cout << t;
    return 0;
}
