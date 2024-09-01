#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;
int N,M;
int board[1010][1010];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin>>board[i][j];
        }
    }
}

struct pos{
    int x;
    int y;
    int value;
};
struct cmp{
    bool operator()(pos a ,pos b){
        return a.value >= b.value;
    }
};
bool visited[1010][1010];
int get(){
    memset(visited,false,sizeof(visited));
    priority_queue<pos,vector<pos>,cmp> pq;
    if(board[0][0] == 2) pq.push({0,0,2});
    else if(board[0][0] == 0) pq.push({0,0,0});
    else if(board[0][0] == 1) pq.push({0,0,1});
    else return -1;
    pos c,n;
    while(!pq.empty()){
        c = pq.top();
        pq.pop();

        if(visited[c.x][c.y]) continue;
        visited[c.x][c.y] = true;
        if(c.x == N-1 && c.y == M-1) return c.value;
        for(int i = 0 ; i < 4 ; i++){
            n.x = c.x + dx[i];
            n.y = c.y + dy[i];
            if(n.x < 0 || n.x > N-1 || n.y < 0 || n.y > M-1 || board[n.x][n.y] == -1 || visited[n.x][n.y]) continue;
            
            if(board[n.x][n.y] == 2) pq.push({n.x,n.y,c.value+2});
            else if(board[n.x][n.y] == 0) pq.push({n.x,n.y,c.value});
            else if(board[n.x][n.y] == 1) pq.push({n.x,n.y,c.value+1});
        }
    }
    
    return -1;
}

int main(void){
    FASTIO;
    input();
    cout<<get();
}
