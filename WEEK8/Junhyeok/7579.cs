using System;
using System.Linq;

using static System.Console;

class Solution_7579 {
    static int activeCount, needMemory;
    static int[] appMemory, cost;
    static int[ , ] dp;

    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        var input = ReadLine().Split(' ').Select(int.Parse).ToArray();
        activeCount = input[0]; needMemory = input[1];

        appMemory = ReadLine().Split(' ').Select(int.Parse).ToArray();
        cost = ReadLine().Split(' ').Select(int.Parse).ToArray();

        dp = new int[activeCount + 1, cost.Sum() + 1];
    }

    static void Solution() {
        int answer = Int32.MaxValue;
        
        for(int i = 1; i <= activeCount; i++) {
            for(int j = 0; j <= cost.Sum(); j++) {
                if(cost[i - 1] > j) dp[i, j] = dp[i - 1, j];
                else {
                    dp[i, j] = Math.Max(dp[i - 1, j], dp[i - 1, j - cost[i - 1]] + appMemory[i - 1]);
                    if(dp[i, j] >= needMemory) answer = Math.Min(answer, j);
                }
            }
        }

        WriteLine(answer);
    }
}
