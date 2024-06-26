using System;
using System.Linq;

using static System.Console;

/*
  이 문제는 최악의 경우 10^9 * 10^9 = 10^18(1,000,000,000,000,000,000) 의 값을 저장해야할 경우가 있다.
  ㄴ 심사대는 1자리 밖에 없고, 걸리는 시간은 10^9에 사람 수는 10^9일 경우

  그러므로 10^18 이상의 값을 저장할 수 있는 자료형을 사용해야 풀 수 있다.
  c# 기준 ulong, BigInteger
*/

class Solution_2792 {
    static ulong human, table;
    static ulong[] time;
    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        var value = ReadLine().Split(' ').Select(ulong.Parse).ToArray();
        human = value[1]; table = value[0];
        time = new ulong[table];
        for(ulong i = 0; i < table; i++)
            time[i] = ulong.Parse(ReadLine());
    }

    static void Solution() {
        ulong left = 1;
        ulong right = time.Max() * human;
        ulong answer = 0;

        while(left <= right) {
            ulong mid = (left + right) / 2;
            // 심사 가능하면 더 짧은 시간으로 시도해본다.
            if(MoreHuman(mid)) {
                right = mid - 1;
                answer = mid;
            }
            else left = mid + 1;
        }

        WriteLine(answer);
    }

    /*
      이전 문제의 보석 상자와 풀이 방법은 비슷하지만 입국심사는 반대로 생각한다.
      총 걸리는 시간을 가져오고, 이 시간안에 심사를 끝낼 수 있는지 확인한다.
    */
    static bool MoreHuman(ulong t) {
        ulong h = 0;
        for(ulong i = 0; i < table; i++) h += t / time[i];
        return h >= human;
    }
}
