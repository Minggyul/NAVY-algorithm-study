using System;
using System.Linq;
using System.Collections.Generic;

using static System.Console;

/*
  (r, c) = (x, y) 라고 착각할 수 있는 문제이다.
  r = 북쪽에서부터 떨어진 거리
  c = 서쪽에서부터 떨어진 거리
*/

class Solution_14499 {
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[] dice = {0, 0, 0, 0, 0, 0};
    static int n, m, x, y;
    static int[] order;
    static int[ , ] field;
    
    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        var data = ReadLine().Split(' ').Select(int.Parse).ToArray();
        n = data[0]; m = data[1]; y = data[2]; x = data[3];
        
        field = new int[n, m];
        for(int i = 0; i < n; i++) {
            var map = ReadLine().Split(' ').Select(int.Parse).ToArray();
            for(int j = 0; j < m; j++) {
                field[i, j] = map[j];
            }
        }

        order = ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    static void Solution() {
        foreach(int direction in order) {
            if(AvailableRoll(direction)) {
                Roll(direction);
                if(field[y, x] == 0) field[y, x] = dice[5];
                else {
                    dice[5] = field[y, x];
                    field[y, x] = 0;
                }
                WriteLine(dice[0]);
            }
        }
    }

    static void Roll(int direction) {
        if(direction == 1) {
            swap(ref dice, 0, 2);
            swap(ref dice, 0, 5);
            swap(ref dice, 0, 3);
        } else if(direction == 2) {
            swap(ref dice, 0, 3);
            swap(ref dice, 0, 5);
            swap(ref dice, 0, 2);
        } else if(direction == 3) {
            swap(ref dice, 0, 1);
            swap(ref dice, 0, 5);
            swap(ref dice, 0, 4);
        } else {
            swap(ref dice, 0, 4);
            swap(ref dice, 0, 5);
            swap(ref dice, 0, 1);
        }

        x += dx[direction - 1];
        y += dy[direction - 1];
    }

    static bool AvailableRoll(int direction) {
        int cx = x + dx[direction - 1];
        int cy = y + dy[direction - 1];

        return !(cx < 0 || cx >= m || cy < 0 || cy >= n);
    }

    static void swap(ref int[] arr, int first, int second) {
        int tmp = arr[first];
        arr[first] = arr[second];
        arr[second] = tmp;
    }
}
