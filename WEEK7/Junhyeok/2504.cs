using System;
using System.Linq;
using System.Collections.Generic;

using static System.Console;

class Solution_2504 {
    static void Main() {
        var str = ReadLine();
        var stack = new Stack<char>();
        int sum = 0;
        int tmp = 1;
        bool prevClosed = false; // 이전이 닫힌 괄호인지 아닌지 확인

        foreach(char c in str) {
            if(c == '(' || c == '[') {
                prevClosed = false;
                tmp *= c == '(' ? 2 : 3;
                stack.Push(c);
                continue;
            }

            if(stack.Count == 0 || (c == ']' && stack.Peek() == '(') || (c == ')' && stack.Peek() == '[')) {
                WriteLine(0);
                return;
            }

            if(!prevClosed) {
                sum += tmp;
                prevClosed = true;
            }
            tmp /= c == ')' ? 2 : 3;
            stack.Pop();
        }

        WriteLine(stack.Count > 0 ? 0 : sum);
    }
}
