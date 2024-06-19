using System;
using System.Linq;
using System.Collections.Generic;

class Baekjoon {
    static int caseCount, n, a, b;
    static int[] tree;
    static bool[] check;

    static void Main() {
        Solution();
    }

    static void Solution() {
        caseCount = int.Parse(Console.ReadLine());
        for(int i = 0; i < caseCount; i++) {
            InputData();
            var ancestor = GetAncestor();
            Console.WriteLine(ancestor);
        }
    }

    static void InputData() {
        n = int.Parse(Console.ReadLine());
        tree = new int[n + 1];
        check = new bool[n + 1];

        for(int j = 1; j < n; j++) {
            int[] value = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            tree[value[1]] = value[0];
        }
        
        int[] nodes = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        a = nodes[0]; b = nodes[1];
    }

    /*
        A부터 루트 노드까지 탐색 후 B부터 루트 노드 탐색
    */
    static int GetAncestor() {
        while(a != 0) {
            check[a] = true;
            a = tree[a];
        }

        while(!check[b]) {
            check[b] = true;
            b = tree[b];
        }

        return b;
    }
}
