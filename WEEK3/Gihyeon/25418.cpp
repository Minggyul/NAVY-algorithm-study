#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool check[1000010];
int main(void){
    memset(check,false,sizeof(check));
    int f,l;
    cin>>f>>l;
    queue<pair<int,int>> q;
    q.push(make_pair(f,0));
    pair<int,int> n;
    while(1){
        n = q.front();
        q.pop();
        if(n.first == l){
            cout<<n.second;
            break;
        }
        if(n.first*2 <= 1000000 && check[n.first*2] == false){
            q.push(make_pair(n.first*2,n.second+1));
            check[n.first*2] = true;
        }
        if(n.first+1 <= 1000000 && check[n.first+1] == false){
            q.push(make_pair(n.first+1,n.second+1));
            check[n.first+1] = true;
        }
    }
}
