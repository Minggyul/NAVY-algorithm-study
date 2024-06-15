// 역순으로 연산하여 푼 코드
#include <iostream>

using namespace std;

int main() {
    int a, k, count = 0;
    cin >> a >> k;
    
    while(a != k) {
        if(k % 2 == 0 && k / 2 >= a) k /= 2;
        else k -= 1;
        count++;
    }
    
    cout << count;
    return 0;
}


// BFS 방법으로 푼 코드 -> 시간 초과
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    int a, k, count;
    cin >> a >> k;
    
    if(a == k) {
        cout << 0;
        return 0;
    }
    
    queue<pair<int, int>> queue;
    queue.push(make_pair(1, a));
    
    while(true) {
        pair<int, int> pair = queue.front();
        queue.pop();
        
        if(pair.second * 2 == k || pair.second + 1 == k) {
            count = pair.first;
            break;
        }
        
        if(pair.second + 1 < k)
            queue.push(make_pair(pair.first + 1, pair.second + 1));
        if(pair.second * 2 < k)
            queue.push(make_pair(pair.first + 1, pair.second * 2));
    }
    
    cout << count;
    return 0;
}
