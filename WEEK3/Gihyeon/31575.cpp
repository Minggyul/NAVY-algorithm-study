#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int board[304][304];
bool check[304][304];
int N,M;
void input(){
    cin>>M>>N;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            cin>>board[i][j];
}

bool bfs(){
    pair<int,int> c,n;
    c = make_pair(0,0);
    queue<pair<int,int>> q;
    q.push(c);
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(c.first == N-1 && c.second == M-1) return true;
        
        if(check[c.first][c.second]) continue;
        check[c.first][c.second] = true;
        
        n = make_pair(c.first+1,c.second);
        if(n.first >= 0 && n.first <= N-1 && n.second >= 0 && n.second <= M-1 && board[n.first][n.second] == 1 && !check[n.first][n.second]) q.push(n);
        
        n = make_pair(c.first,c.second+1);
        if(n.first >= 0 && n.first <= N-1 && n.second >= 0 && n.second <= M-1 && board[n.first][n.second] == 1 && !check[n.first][n.second]) q.push(n);
    }
    return false;
}

int main(void){
    input();
    if(bfs()) cout<<"Yes";
    else cout<<"No";
}