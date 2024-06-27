using System;
using System.Linq;

using static System.Console;

/*
  그룹을 나눠서 푸는게 아닌 최소값을 미리 지정해둔 후 그룹을 나누는 방법으로 풀어야한다.
*/

class Solution_17951 { 
    static int paper, group;
    static int[] score;

    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        int[] value = ReadLine().Split(' ').Select(int.Parse).ToArray();
        paper = value[0]; group = value[1];
        score = ReadLine().Split(' ').Select(int.Parse).ToArray();
    }

    static void Solution() {
        int left = 0;
        int right = score.Sum();
        int answer = 0;

        while(left <= right) {
            int mid = (left + right) / 2;
            if(divideScore(mid)) {
                left = mid + 1;
                answer = mid;
            }
            else right = mid - 1;
        }

        Write(answer);
    }

    static bool divideScore(int maxScore) {
        int divideGroup = 0;
        int totalScore = 0;
        for(int i = 0; i < paper; i++) {
            totalScore += score[i];
            if(totalScore >= maxScore) {
                divideGroup++;
                totalScore = 0;
            }
        }

        return divideGroup >= group;
    }
}
