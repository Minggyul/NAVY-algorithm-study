#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int k, n, dir, res, cnt = 1;
string s[5];
bool flag[5];

void rev (int idx, int d){
    if (d == 1){
        int tmp = s[idx][7];
        for (int i = 7; i > 0; i--)
            s[idx][i] = s[idx][i - 1];
        s[idx][0] = tmp;
    }
    else{
        int tmp = s[idx][0];
        for (int i = 1; i < 8; i++)
            s[idx][i - 1] = s[idx][i];
        s[idx][7] = tmp;        
    }
}

int main(){
    FASTIO;
    
    for (int i = 1; i <= 4; i++) cin >> s[i];
    cin >> k;
    for (int i = 0; i < k; i++){
        memset(flag, 0, sizeof(flag));
        cin >> n >> dir;
        
        for (int j = n - 1; j >= 1; j--){
            if (s[j][2] != s[j + 1][6]) flag[j] = true;
            else break;
        }
        for (int j = n + 1; j <= 4; j++){
            if (s[j - 1][2] != s[j][6]) flag[j] = true;
        }
        
        rev(n, dir);
        int tmp = dir;
        for (int j = n - 1; j >= 1; j--){
            tmp *= -1;
            if (flag[j]) rev(j, tmp);
            else break;
        }
        for (int j = n + 1; j <= 4; j++){
            dir *= -1;
            if (flag[j]) rev(j, dir);
            else break;
        }
    }
    
    for (int i = 1; i <= 4; i++){
        if (s[i][0] == '1') res += cnt;
        cnt *= 2;
    }
    cout << res;
    return 0;
}
