using System;
using System.Linq;
using System.Collections.Generic;

class Baekjoon {
    static int n;
    static bool[ , ] graph;
    static bool[ , ] isVisited;

    static void Main() {
        InputData();
        Solution();
        PrintGraph();
    }

    static void InputData() {
        n = int.Parse(Console.ReadLine());
        graph = new bool[n, n];
        isVisited = new bool[n, n];
        
        for(int i = 0; i < n; i++) {
            int[] value = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            for(int j = 0; j < n; j++) {
                graph[i, j] = (value[j] == 1) ? true : false;
            }
        }
    }

    static void Solution() {
        for(int i = 0; i < n; i++) {
            Dfs(i);
        }
    }

    static void Dfs(int start) {
        var stack = new Stack<int>();
        for(int i = 0; i < n; i++) {
            if(!graph[start, i]) continue;
            
            isVisited[start, i] = true;
            stack.Push(i);

            while(stack.Count != 0) {
                int next = stack.Pop();
                for(int j = 0; j < n; j++) {
                    if(!graph[next, j] || isVisited[start, j]) continue;

                    isVisited[start, j] = true;
                    stack.Push(j);
                }
            }
        }
    }

    static void PrintGraph() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Console.Write($"{isVisited[i, j] ? 1 : 0} ");
            }
            Console.WriteLine();
        }
    }
}
