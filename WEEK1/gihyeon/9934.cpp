#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;
int arr[(1<<11)];
vector <int> result[15];
int arrlen;
int N;
void input(){
    cin>>N;
    arrlen = (1<<(N))-1;
    for(int i = 1 ; i <= arrlen ; i++){
        cin>>arr[i];
    }
    
}
void make_result(int lo, int hi, int temp){
    if(lo == hi){
        result[N-temp].push_back(arr[lo]) ;
        return;
    }
    int mid = lo+(1<<(temp-1))-1;
    result[N-temp].push_back(arr[mid]);
    make_result(lo, mid-1, temp-1);
    make_result(mid+1, hi, temp-1);
}
void print_result(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < result[i].size() ; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main(void){
    input();
    make_result(1,arrlen,N);
    print_result();
}