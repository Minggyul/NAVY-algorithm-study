#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
const int MAX = 1e6 + 1;
int dist[MAX];

void solved(){
    queue<int> q;
    q.push(n);
    dist[n] = 1;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        if (x == k) {
            cout << dist[x] - 1;
            return ;
        }
        
        int next = x + 1;
        if (dist[next] == 0) {
            q.push(next);
            dist[next] = dist[x] + 1;
        }
        
        next = 2 * x;
        if (next < MAX && dist[next] == 0){
            q.push(next);
            dist[next] = dist[x] + 1;
        }
    }
}

int main() {
    FASTIO;
    
    cin >> n >> k;
    solved();
    
    return 0;
}

/* 14756: 정수 a를 k로 만들기 (S3) (-)
연산 1: 정수 A에 1을 더한다.
연산 2: 정수 A에 2를 곱한다.
정수 A를 정수 K로 만들기 위해 필요한 최소 연산 횟수
*/ 
