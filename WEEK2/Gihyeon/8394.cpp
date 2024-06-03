#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
// 이게 뭔 문제여
// 피보나치 수열이 되네 ?
int N1;

int main512(void){
    cin>>N1;
    if(N1 == 1 || N1 == 2){
        cout<<N1;
        return 0;
    }
    int n1 = 1, n2 = 2;
    for(int i = 3; i <= N1 ; i++){
        int temp = n2;
        n2 = (n1+n2)%10;
        n1 = temp;
    }
    cout<<n2%10;
}   