
#include <iostream>
2
#include <queue>
3
#include <algorithm>
4
#include <cstring>
5
#include <map>
6
#include <cmath>
7
​
8
using namespace std;
9
​
10
int N,M,K;
11
int l[2010][2010];
12
char board[2010][2010];
13
void input(){
14
    cin>>N>>M>>K;
15
    for(int i = 0 ;i < N ;i++){
16
        for(int j = 0 ; j < M ; j++){
17
            cin>>board[i][j];
18
        }
19
    }
20
​
21
}
22
void get_one(int row){
23
    int now = 0;
24
    for(int i = 0 ; i < K ;i++){
25
        if((i+row)%2 == 0 && board[row][i] == 'W'){
26
            now++;
27
        }
28
        if((i+row)%2 == 1 && board[row][i] == 'B'){
29
            now++;
30
        }
31
    }
32
    l[row][0] = now;      //6
33
    
34
    for(int i = K ; i < M ; i++){
35
        now = K - now;
36
        if((row)%2 == 0 && board[row][i-K] == 'B') now--;
37
        else if((row)%2 == 1 && board[row][i-K] == 'W') now--;
38
​
39
        if((row+K-1)%2 == 0 && board[row][i] == 'W') now++;
40
        else if((row+K-1)%2 == 1 && board[row][i] == 'B') now++;
41
        l[row][i-K+1] = now;
42
        now = l[row][i-K+1];   
43
    }
44
}
45
int get(){
46
    for(int i = 0; i < N ; i++){
47
        get_one(i);
48
    }
49
    
50
    int ret = 1e9;
51
    for(int j = 0 ; j <= M-K ; j++){
52
        int now = 0;
53
        for(int i = 0 ; i < K ; i++){
54
            now += l[i][j];
55
        }
56
        ret = min(now, ret);
57
        ret = min((K*K)-now, ret);
58
​
59
        for(int i = K ; i < N ;i++){
60
            now -= l[i-K][j];
61
            now += l[i][j];
62
            
63
            ret = min(now,ret);
64
            ret = min((K*K)-now, ret);
65
​
66
        }
67
        
68
    }
69
    return ret;
70
}
71
int main(void){
72
    input();
73
    cout<<get()<<"\n";
74
​
75
}
