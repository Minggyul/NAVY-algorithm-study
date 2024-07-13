using System;
using System.Linq;

using static System.Console;

class Solution_14891 {
    static char[ , ] sawTooth = new char[4, 8];
    static bool[] check = new bool[4];

    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        for(int i = 0; i < 4; i++) {
            var tmp = ReadLine();
            for(int j = 0; j < 8; j++) {
                sawTooth[i, j] = tmp[j];
            }
        }
    }

    static void Solution() {
        int result = 0;
        int count = int.Parse(ReadLine());
        for(int i = 0; i < count; i++) {
            var input = ReadLine().Split(' ').Select(int.Parse).ToArray();
            var saw = input[0] - 1;
            var rotate = input[1];

            DoRotation(saw, rotate);
            for(int j = 0; j < 4; j++) check[j] = false;
        }

        for(int i = 0; i < 4; i++) {
            if(sawTooth[i, 0] == '1') result += 1 << i;
        }

        WriteLine(result);
    }

    static void DoRotation(int saw, int rotate) {
        check[saw] = true;
        
        char[] newSaw = new char[8];
        for(int i = 0; i < 8; i++) {
            newSaw[i] = sawTooth[saw, (i + 8 - rotate) % 8];
        }

        if(saw - 1 >= 0 && sawTooth[saw, 6] != sawTooth[saw - 1, 2] && !check[saw - 1]) DoRotation(saw - 1, rotate * (-1));
        if(saw + 1 < 4 && sawTooth[saw, 2] != sawTooth[saw + 1, 6] && !check[saw + 1]) DoRotation(saw + 1, rotate * (-1));

        for(int i = 0; i < 8; i++) {
            sawTooth[saw, i] = newSaw[i];
        }
    }
}
