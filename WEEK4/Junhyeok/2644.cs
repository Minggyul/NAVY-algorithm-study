using System;
using System.Linq;
using System.Collections.Generic;

class Solution {
    static int n, x, y, m; // 가족 수 , 첫 번째 사람, 두 번째 사람, 관계 수
    static bool[ , ] family;
    static bool[] check;
    
    static void Main() {
        InputData();
        var kinship = GetKinship();
        Console.Write(kinship);
    }

    static void InputData() {
        n = int.Parse(Console.ReadLine());
        int[] value = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        x = value[0]; y = value[1];
        m = int.Parse(Console.ReadLine());
        family = new bool[n + 1, n + 1];
        check = new bool[n + 1];

        for(int i = 0; i < m; i++) {
            int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            family[input[0], input[1]] = family[input[0], input[1]] = true;
        }
    }

    static int GetKinship() {
        var stack = new Stack<(int, int)>(); // 촌수 , 번호
        stack.Push((0, x));
        check[x] = true;

        while(stack.Count != 0) {
            (int number, int v) = stack.Pop();
            if(v == y) return number;
            
            for(int i = 1; i <= n; i++) {
                if((family[v, i] || family[i, v]) && !check[i]) {
                    stack.Push((number + 1, i));
                    check[i] = true;
                }
            }
        }

        return -1;
    }
}
