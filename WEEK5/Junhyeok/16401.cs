using System;
using System.Linq;

using static System.Console;

class Solution_16401 {
    static int human, stickCount;
    static int[] sticks;
    
    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        int[] value = ReadLine().Split(' ').Select(int.Parse).ToArray();
        human = value[0]; stickCount = value[1];
        sticks = ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    static void Solution() {
        int left = 1;
        int right = sticks.Max();

        while(left <= right) {
            int mid = (left + right) / 2;
            // 나눠줄 수 있으면 나누는 길이를 늘리고, 못 나눠주면 길이 줄이기
            if(CanHandOut(mid)) left = mid + 1;
            else right = mid - 1;
        }

        Write(right);
    }

    static bool CanHandOut(int length) {
        int divideCount = 0;
        for(int i = 0; i < stickCount; i++) {
            divideCount += sticks[i] / length;
        }

        // 나눈 수가 human 보다 적으면 length 만큼 못 나눠줌
        return divideCount >= human;
    }
}
