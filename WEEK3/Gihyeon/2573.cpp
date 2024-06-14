#include <iostream>
#include <algorithm>
#include <cstring>

#include <vector>
#include <queue>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct pos{
    int x;
    int y;
};

int maxx,maxy;
int board[305][305];

void input(){
    cin>>maxx>>maxy;
    for(int i = 0 ; i < maxx ; i++)
        for(int j = 0 ; j < maxy ; j++)
            cin>>board[i][j];
}

bool visited[305][305];
void bfs(int fx, int fy){
    pos n,c;
    cpos = {fx,fy};
    queue <pos> q;
    q.push(c);
    visited[c.x][c.y] = true;
    
    while(!q.empty()){
        cpos = q.front();
        q.pop();
        
        for(int i = 0 ; i < 4 ; i++){
            npos.x = cpos.x + dx[i];
            npos.y = cpos.y + dy[i];
            
            if(n.x < 0 || n.x > maxx-1 || n.y < 0 || n.y > maxy-1 || visited[n.x][n.y]) continue;
            
            if(board[n.x][n.y] > 0){
                q.push(n);
                visited[n.x][n.y] = true;
            }
            else{
                if(board[c.x][c.y] > 0)
                    board[c.x][c.y]--;
            }
        }
    }
    
    return;
    
    
    
}

int getresult(){
    int returnresult = 0;
    while(1){
        int cnt = 0;
        memset(visited,false,sizeof(visited));
        for(int i = 0 ; i < maxx ; i++){
            for(int j = 0 ; j < maxy ; j++){
                if(board[i][j] > 0 && !visited[i][j]){
                    cnt++;
                    bfs(i,j);
                }
            }
        }

        if(cnt == 0) return 0;
        if(cnt >= 2) return returnresult;
        
        cnt = 0;
        returnresult++;
            
    }
}

int main(void){
    input();
    cout<<getresult()<<"\n";
}