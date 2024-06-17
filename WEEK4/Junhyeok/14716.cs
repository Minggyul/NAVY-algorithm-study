using System;
using System.Linq;
using System.Collections.Generic;

namespace Baekjoon {
    class Solution {
        static int[] dx = {0, 1, 1, 1, 0, -1, -1, -1};
        static int[] dy = {1, 1, 0, -1, -1, -1, 0, 1};
        static int m, n;
        static int[ , ] field;
        static bool[ , ] check;
        
        static void Main() {
            inputValue();
            var count = getCharacterCount();
            Console.Write(count);
        }

        static void inputValue() {
            int[] value = Console.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
            m = value[0];
            n = value[1];
            field = new int[m, n];
            check = new bool[m, n];
            
            for(int i = 0; i < m; i++) {
                int[] fieldValue = Console.ReadLine().Split(new[] {' '}, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
                for(int j = 0; j < n; j++) {
                    field[i, j] = fieldValue[j];
                }
            }
        }

        static int getCharacterCount() {
            var stack = new Stack<(int x, int y)>();
            int count = 0;
            for(int y = 0; y < m; y++) {
                for(int x = 0; x < n; x++) {
                    if(field[y, x] == 0 || check[y, x]) continue;
                    
                    count++;
                    stack.Push((x, y));
                    while(stack.Count != 0) {
                        var pos = stack.Pop();
                        for(int i = 0; i < 8; i++) {
                            var cx = pos.x + dx[i];
                            var cy = pos.y + dy[i];
    
                            if(cx < 0 || cx >= n || cy < 0 || cy >= m || field[cy, cx] == 0 || check[cy, cx]) continue;

                            check[cy, cx] = true;
                            stack.Push((cx, cy));
                        }
                    }
                }
            }

            return count;
        }
    }
}
