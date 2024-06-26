using System;
using System.Linq;

using static System.Console;

class Solution_2792 {
    static int human, colorCount, total = 0;
    static int[] colors;
    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        var value = ReadLine().Split(' ').Select(int.Parse).ToArray();
        human = value[0]; colorCount = value[1];
        colors = new int[colorCount];
        for(int i = 0; i < colorCount; i++) {
            colors[i] = int.Parse(ReadLine());
            total += colors[i];
        }
    }

    static void Solution() {
        int left = 1;
        int right = colors.Max();

        while(left <= right) {
            int mid = (left + right) / 2;
            // 더 많이 나눠줄 수 있으므로 left 높이기
            if(isEvenOut(mid)) left = mid + 1;
            // 적거나 같을 경우엔 right 낮추기
            else right = mid - 1;
        }

        WriteLine(left);
    }

    /*
      코드를 고치다보니 함수명을 의도와 맞지 않게 작성함
      보석을 나눠줄 때 현 인원보다 더 많이 나눠줄 수 있는지 확인하는 함수
    */
    static bool isEvenOut(int count) {
        int divide = 0;
        for(int i = 0; i < colorCount; i++) {
            divide += colors[i] / count;
            if(colors[i] % count != 0) divide++;
        }

        return divide > human;
    }
}
