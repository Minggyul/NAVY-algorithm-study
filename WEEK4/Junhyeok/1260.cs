using System;
using System.Linq;
using System.Collections.Generic;

class Solution {
    static int n, m, start;
    static bool[ , ] graph;
    static bool[] dfsVisited;
    static bool[] bfsVisited;
    
    static void Main() {
        InputData();
        Dfs(start);
        Console.WriteLine();
        Bfs();
    }
    
    static void InputData() {
        int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        n = input[0]; m = input[1]; start = input[2];
        
        graph = new bool[n + 1, n + 1];
        dfsVisited = new bool[n + 1];
        bfsVisited = new bool[n + 1];
        for(int i = 0; i < m; i++) {
            int[] value = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            graph[value[0], value[1]] = graph[value[0], value[1]] = true;
        }
    }

    static void Dfs(int start) {
        Console.Write($"{start} ");
        dfsVisited[start] = true;

        for(int i = 1; i <= n; i++) {
            if((graph[start, i] || graph[i, start]) && !dfsVisited[i]) Dfs(i);
        }
    }

    static void Bfs() {
        var queue = new Queue<int>();
        queue.Enqueue(start);
        bfsVisited[start] = true;

        while(queue.Count != 0) {
            int v = queue.Dequeue();
            Console.Write($"{v} ");

            for(int i = 1; i <= n; i++) {
                if((graph[v, i] || graph[i, v]) && !bfsVisited[i]) {
                    queue.Enqueue(i);
                    bfsVisited[i] = true;
                } 
            }
        }
    }
}
