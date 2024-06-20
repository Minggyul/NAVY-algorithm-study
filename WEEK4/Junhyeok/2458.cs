using System;
using System.Linq;
using System.Collections.Generic;

public enum CompareType {
    UP, DOWN
}

class Baekjoon {  
    static bool[ , ] graph;
    static int n, m;

    static void Main() {
        InputData();
        int studentCount = GetComparableStudentCount();
        Console.Write(studentCount);
    }

    static void InputData() {
        int[] input = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        n = input[0]; m = input[1];
        graph = new bool[n + 1, n + 1];

        for(int i = 0; i < m; i++) {
            int[] node = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
            graph[node[0], node[1]] = true;
        }
    }

    static int GetComparableStudentCount() {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            /*
              자기보다 작은 사람의 수 + 자기보다 큰 사람의 수 = 전체 사람 수 - 1(자기 제외) 가 성립될 경우, 키 순서를 알 수 있다.
              즉, 양수 거리의 방향으로 이어진 노드들의 수 + 음수 거리의 방향으로 이어진 노드들의 수 = 전체 노드들의 수 - 1 일 경우이다.
            */
            bool isComparable = GetLinkedStudentCount(i, CompareType.UP) + GetLinkedStudentCount(i, CompareType.DOWN) == n - 1;
            if(isComparable) count++;
        }

        return count;
    }

    static int GetLinkedStudentCount(int startNode, CompareType type) {
        var stack = new Stack<int>();
        bool[] isVisited = new bool[n + 1];
        int studentCount = 0;
        stack.Push(startNode);
        isVisited[startNode] = true;

        while(stack.Count != 0) {
            int v = stack.Pop();
            if(type == CompareType.UP) {
                for(int i = 1; i <= n; i++) {
                    if(!graph[v, i] || isVisited[i]) continue;

                    isVisited[i] = true;
                    stack.Push(i);
                    studentCount++;
                }
            } else {
                for(int i = 1; i <= n; i++) {
                    if(!graph[i, v] || isVisited[i]) continue;

                    isVisited[i] = true;
                    stack.Push(i);
                    studentCount++;
                }
            }
        }

        return studentCount;
    }
}
