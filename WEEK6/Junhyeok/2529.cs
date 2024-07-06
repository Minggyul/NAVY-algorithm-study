using System;
using System.Linq;
using System.Text;

using static System.Console;

class Solution_2529 {
    static int count;
    static char[] sign;
    static bool[] isVisited = new bool[10];
    static string minValue = "999999999";
    static string maxValue = "0";
    static StringBuilder stringBuilder = new StringBuilder();

    static void Main() {
        InputData();
        Solution();
        WriteLine(maxValue);
        WriteLine(minValue);
    }

    static void InputData() {
        count = int.Parse(ReadLine());
        sign = ReadLine().Split(' ').Select(char.Parse).ToArray();
    }

    static void Solution() {
        for(int i = 0; i < 10; i++) {
            isVisited[i] = true;
            stringBuilder.Append(i);
            GetResult(0, i);
            isVisited[i] = false;
            stringBuilder.Remove(0, 1);
        }
    }

    static void GetResult(int n, int cur) {
        if(n == count) {
            if(string.Compare(maxValue, stringBuilder.ToString()) == -1) maxValue = stringBuilder.ToString();
            if(string.Compare(minValue, stringBuilder.ToString()) == 1) minValue = stringBuilder.ToString();
            return;
        }

        for(int i = 0; i < 10; i++) {
            if(isVisited[i]) continue;
            
            if(sign[n] == '<' && cur < i) {
                stringBuilder.Append(i);
                isVisited[i] = true;
                GetResult(n + 1, i);
                stringBuilder.Remove(n + 1, 1);
                isVisited[i] = false;
            } else if (sign[n] == '>' && cur > i){
                stringBuilder.Append(i);
                isVisited[i] = true;
                GetResult(n + 1, i);
                stringBuilder.Remove(n + 1, 1);
                isVisited[i] = false;
            }
        }
    }
}
