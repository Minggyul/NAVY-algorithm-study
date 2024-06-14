#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,M;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int board[505][505];
bool check[505][505];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
        }
    }
}
int bfs(int x, int y){
    int cnt = 0;
    queue <pair<int,int>> q;
    q.push(make_pair(x,y));
    pair<int,int> c,n;
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(check[c.first][c.second]) continue;
        check[c.first][c.second] = true;
        cnt++;
        
        for(int i = 0 ; i < 4 ; i++){
            n.first = c.first + dx[i];
            n.second = c.second + dy[i];
            if(n.first < 0 || n.first > N-1 || n.second < 0 || n.second > M-1 || board[n.first][n.second] == 0|| check[n.first][n.second] ) continue;
            q.push(n);
        }
    }
    return cnt;
}
int main(void){
    int result = 0;
    int cnt = 0;
    input();
    memset(check,false,sizeof(check));
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(board[i][j] == 1 && check[i][j] == false){
                cnt++;
                result = max(result,bfs(i,j));
            }
        }
    }
    cout<<cnt<<"\n"<<result;
}