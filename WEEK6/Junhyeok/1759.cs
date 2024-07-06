using System;
using System.Linq;
using System.Text;
using static System.Console;

/*
  모음인 (a, i, u, e, o) 를 미리 배열에 넣어두면 모음 존재 여부 판단을 쉽게 할 수 있다.
*/

static class Solution_1759 {
    static int length, size;
    static char[] arr;
    static char[] vowel = {'a', 'i', 'u', 'e', 'o'};
    static bool[] check;
    static StringBuilder stringBuilder = new StringBuilder();

    static void Main() {
        InputData();
        Solution(0);
    }

    static void InputData() {
        var input = ReadLine().Split(' ').Select(int.Parse).ToArray();
        length = input[0]; size = input[1];
        check = new bool[size];
        arr = ReadLine().Split(' ').Select(char.Parse).OrderBy(n => n).ToArray();
    }

    static void Solution(int count) {
        if(count >= 2) {
            // 정렬이 안되어 있으면 돌아가기
            if(!stringBuilder.ToString().isSorted()) return;
        }

        if(count == length) {
            int vow = 0, con = 0;
            foreach(char c in stringBuilder.ToString()) {
                if(vowel.Contains(c)) vow++;
                else con++;
            }
            // 최소 모음 1개, 자음 2개
            if(vow >= 1 && con >= 2) WriteLine(stringBuilder.ToString());
            return;
        }

        for(int i = 0; i < size; i++) {
            if(check[i]) continue;
            stringBuilder.Append(arr[i]);
            check[i] = true;
            Solution(count + 1);
            check[i] = false;
            stringBuilder.Remove(count, 1);
        }
    }

    // 문자열 정렬 확인
    static bool isSorted(this string str) {
        for(int i = 0; i < str.Length - 1; i++) {
            if(str[i] > str[i + 1]) return false;
        }
        return true;
    }
}
