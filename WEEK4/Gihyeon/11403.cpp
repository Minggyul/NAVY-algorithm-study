#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N;
int board[105][105];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N;  i++){
        for(int j = 1 ; j <= N;  j++){
            cin>>board[i][j];
        }
    }
}
bool check[105][105];
void get(int first){
    queue<int> q;
    for(int i = 1 ; i <= N ; i++){
        if(board[first][i] == 1){
            q.push(i);
            check[first][i] = true;
        }
    }
    int c;
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        for(int i = 1 ; i <= N ; i++){
            if(board[c][i] == 1 && check[first][i] == false){
                q.push(i);
                check[first][i] = true;
            }
        }
    }
}

int main(void){
    input();
    memset(check,false,sizeof(check));
    for(int i = 1 ; i <= N ; i++){
        get(i);
    }
    for(int i = 1 ; i <= N;  i++){
        for(int j = 1 ; j <= N;  j++){
            if(check[i][j]) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
}