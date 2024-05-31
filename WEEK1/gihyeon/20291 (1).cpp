//200ms
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<string> result;
int N;
void input(){
    string str;
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        cin>>str;
        int idx = str.find(".");
        str = str.substr(idx+1);
        result.push_back(str);
    }
}

void print_result(){
    sort(result.begin(),result.end());
    int cnt = 1;
    for(int i = 0;  i < N-1 ; i++){
        if(result[i] == result[i+1]) cnt++;
        else{
            cout<<result[i]<<" "<<cnt<<"\n";
            cnt = 1;
        }
    }
    cout<<result[N-1]<<" "<<cnt<<"\n";
}

int main(void){
    input();
    print_result();
}