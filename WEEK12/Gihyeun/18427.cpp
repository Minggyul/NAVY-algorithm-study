#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <cmath>
#include <sstream>
#define FASTIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;

int N, M, H;
vector<int> blocks[55];
int blockheight[55];

void input(){
    cin >> N >> M >> H;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int blockHeight;
        
        while (ss >> blockHeight) {
            blocks[i].push_back(blockHeight);
        }
        blockheight[i] = blocks[i].size();
    }

    for (int i = 0; i < N; i++){
        sort(blocks[i].begin(),blocks[i].end());
    }

}
int cashe[55][1010];
int get(int idx, int height){
    if(height == H){
        return 1;
    }
    if(idx > N) return 0;

    if(cashe[idx][height] != -1) return cashe[idx][height];
    int& ret = cashe[idx][height];
    ret = 0;
    
    ret += get(idx+1,height);
    for(int i = 0 ; i < blockheight[idx] ; i++){
        if(H < height+blocks[idx][i]) continue;
        ret += get(idx+1,height+blocks[idx][i]);
    }
    ret%=10007;
    return ret;
}
int main(void){
    FASTIO;
    input();
    memset(cashe,-1,sizeof(cashe));
    cout<<get(0,0);
}