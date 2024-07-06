#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

const int MAXN = 7;
int n;
char arr[MAXN][MAXN];
bool visited[MAXN][MAXN];

bool validation(){
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == 'T'){
                for (int x = i - 1; x >= 0; x--){
                    if (arr[x][j] == 'O') break;
                    visited[x][j] = true;
                }
                for (int x = i + 1; x < n; x++){
                    if (arr[x][j] == 'O') break;
                    visited[x][j] = true;
                }
                for (int y = j - 1; y >= 0; y--){
                    if (arr[i][y] == 'O') break;
                    visited[i][y] = true;
                }
                for (int y = j + 1; y < n; y++){
                    if (arr[i][y] == 'O') break;
                    visited[i][y] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] == 'S' && visited[i][j]) return false;
        }
    }
    return true;
}

int main(){
    FASTIO;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++) cin >> arr[i][j];
	
	for (int a1 = 0; a1 < n; a1++){
	    for (int b1 = 0; b1 < n; b1++){
        	for (int a2 = 0; a2 < n; a2++){
        	    for (int b2 = 0; b2 < n; b2++){
                 	for (int a3 = 0; a3 < n; a3++){
                	    for (int b3 = 0; b3 < n; b3++){
                	        if ((a1 == a2 && b1 == b2) || (a2 == a3 && b2 == b3) || (a1 == a3 && b1 == b3)) continue;
                	        if (arr[a1][b1] != 'X' || arr[a2][b2] != 'X' || arr[a3][b3] != 'X') continue;
                	        arr[a1][b1] = arr[a2][b2] = arr[a3][b3] = 'O';
                	        
                	        if (validation()) {
                	            cout << "YES";
                	            return 0;
                	        }

                	        arr[a1][b1] = arr[a2][b2] = arr[a3][b3] = 'X';
                	    }
                	}       	        
        	    }
        	}	        
	    }
	}
	cout << "NO";
	return 0;
}
