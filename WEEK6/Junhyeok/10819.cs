using System;
using System.Linq;

using static System.Console;

/*
  브루트포스 알고리즘을 사용하여 모든 경우의 수를 다 구한 후 최댓값을 구하면 된다.
*/

class Solution_10819 {
    static int count;
    static int[] numbers;
    static bool[] isVisted;
    static int result = 0;
    static int maxResult = 0;

    static void Main() {
        InputData();
        Solution();
        Write(maxResult);
    }

    static void InputData() {
        count = int.Parse(ReadLine());
        numbers = ReadLine().Split(' ').Select(int.Parse).ToArray();
        isVisted = new bool[count];
    }

    static void Solution() {
        for(int i = 0; i < count; i++) {
            isVisted[i] = true;
            GetResult(1, i);
            isVisted[i] = false;
        }
    }

    static void GetResult(int n, int cur) {
        if(n == count) {
            maxResult = Math.Max(maxResult, result);
            return;
        }

        for(int i = 0; i < count; i++) {
            if(isVisted[i]) continue;

            int cal = Math.Abs(numbers[cur] - numbers[i]);
            result += cal;
            isVisted[i] = true;
            GetResult(n + 1, i);
            result -= cal;
            isVisted[i] = false;
        }
    }
}
