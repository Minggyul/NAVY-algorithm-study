#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string s; 
stack<int> st;

bool check(){
    bool flag = true;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ')'){
            if (st.empty() || st.top() != '(') {
                flag = false;
                break;
            }
            st.pop();
        }
        else if (s[i] == ']'){
            if (st.empty() || st.top() != '['){
                flag = false;
                break;
            }
            st.pop();
        }
        else st.push(s[i]);
    }
    if (!st.empty()) flag = false;
    if (!flag) return false;
    return true;
}

void solved(int idx){
    if (st.top() == idx) {
        st.pop();
        if (!st.empty() && st.top() > 0){
            int k = st.top();
            st.pop();
            st.push(k - idx);
        }
        else st.push(-idx);
    }
    else{
        int k = st.top();
        st.pop();
        st.pop();
        if (!st.empty() && st.top() > 0){
            int j = st.top();
            st.pop();
            st.push(j + (-idx * k));
        }
        else st.push(-idx * k);
    }    
}

int main(){
    FASTIO;
    
    cin >> s;
    if(!check()) {
        cout << 0;
        return 0;
    }
    
    for (int i = 0; i < s.size(); i++){
        if (s[i] == ')') solved(-2);
        else if (s[i] == ']') solved(-3);          
        else {
            if (s[i] == '(') st.push(-2);
            else st.push(-3);
        }
    }
    
    cout << st.top();
    return 0;
}
