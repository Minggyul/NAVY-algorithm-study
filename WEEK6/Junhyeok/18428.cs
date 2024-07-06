using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

/*
  X위치에 3개의 벽을 쌓는 모든 경우의 수를 구한 후,
  3개 설치할 때 마다 T의 위치로부터 상하좌우 탐색한 후 S가 발견되면 다음 경우의 수로, 발견 안되면 YES 출력 후 프로그램 종료
*/

class Solution_18428 {
    static int size;
    static string[ , ] field;
    static bool[ , ] check;
    static bool isAvailable = false;
    static List<(int x, int y)> teacherPos = new List<(int x, int y)>();

    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        size = int.Parse(ReadLine());
        field = new string[size, size];
        check = new bool[size, size];
        for(int i = 0; i < size; i++) {
            var tmp = ReadLine().Split(' ').ToArray();
            for(int j = 0; j < size; j++) {
                field[i, j] = tmp[j];
                if(tmp[j] == "T") teacherPos.Add((j, i));
            }
        }
    }

    static void Solution() {
        Backtracking(0);
        if(isAvailable) WriteLine("YES");
        else WriteLine("NO");
    }

    static void Backtracking(int count) {
        if(count == 3) {
            if(isHide()) isAvailable = true;
            return;
        }

        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(check[i, j] || field[i, j] == "S" || field[i, j] == "T") continue;

                field[i, j] = "O";
                check[i, j] = true;
                Backtracking(count + 1);
                check[i, j] = false;
                field[i, j] = "X";

                if(isAvailable) return;
            }
        }
    }

    static bool isHide() {
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        foreach(var pos in teacherPos) {
            for(int i = 0; i < 4; i++) {
                int x = pos.x;
                int y = pos.y;
                for( ; (x >= 0 && x < size && y >= 0 && y < size); x += dx[i], y += dy[i]) {
                    if(field[y, x] == "O") break;
                    if(field[y, x] == "S") return false;
                }
            }
        }

        return true;
    }
}
