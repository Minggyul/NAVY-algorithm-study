#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAX = 1234;
int l[MAX], r[MAX], arr[MAX], b[MAX];
queue<int> qq;

void inorder(int now){
    if (now == 0) return;
    inorder(l[now]);
    qq.push(now);
    inorder(r[now]);
}

int main(){
    FASTIO;

    // 1 ~ 2^k - 1까지의 배열을 만들어보자
    int k, res = 1, t = 1;
    cin >> k;
    for (int i = 0; i < k; i++) res *= 2;
    res -= 1;

    queue<int> q;
    q.push(1);
    while(t < res){
        int top = q.front();
        q.pop();

        l[top] = ++t;
        r[top] = ++t;
        q.push(l[top]);
        q.push(r[top]);
    }

    // in - order 구현
    inorder(1);

    // Matching
    for (int i = 1; i <= res; i++) cin >> arr[i];
    for (int i = 1; i <= res; i++){
        int top = qq.front();
        qq.pop();
        b[top] = arr[i]; // 예를 들어 b[4] = arr[0] = 1 이면 4번째 수는 1인거
    }
    
    // 출력
    int j = 1;
    for (int i = 1; i <= res; i++){
        cout << b[i] << ' ';
        if (i == j) {
            cout << '\n';
            j = (j + 1) * 2 - 1;
        }
    }
    return 0;
}
