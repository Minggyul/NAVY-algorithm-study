using System;
using System.Linq;
using System.Collections.Generic;

using static System.Console;

class Solution_14503 {
    static int n, m;
    static int[ , ] field;
    static int currentX, currentY, direction;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};
    
    static void Main() {
        InputData();
        Solution();
    }
    
    static void InputData() {
        var size = ReadLine().Split(' ').Select(int.Parse).ToArray();
        n = size[0]; m = size[1];
        var value = ReadLine().Split(' ').Select(int.Parse).ToArray();
        currentX = value[1]; currentY = value[0]; direction = value[2];
        
        field = new int[n, m];
        for(int i = 0; i < n; i++) {
            var fieldData = ReadLine().Split(' ').Select(int.Parse).ToArray();
            for(int j = 0; j < m; j++) {
                field[i, j] = fieldData[j];
            }
        }
    }

    static void Print() {
        WriteLine($"direction : {direction}    x : {currentX}  y : {currentY}");
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == currentY && j == currentX) Write("3 ");
                else Write($"{field[i, j]} ");
            }
            WriteLine();
        }
        WriteLine();
    }
    
    static void Solution() {
        int clean = 0;
        
        while(true) {
            // Print();
            if(!isCleaned()) {
                clean++;
                field[currentY, currentX] = 2;
            }
            
            if(!findDirty()) {
                var backDirection = (direction + 2) % 4;
                var x = currentX + dx[backDirection];
                var y = currentY + dy[backDirection];
                
                if(field[y, x] == 1) break;
                
                currentX = x; currentY = y;
            } else {
                direction = (direction + 3) % 4;
                var x = currentX + dx[direction];
                var y = currentY + dy[direction];
                    
                if(field[y, x] == 0) {
                    currentX = x; currentY = y;
                }
            }
        }
        
        WriteLine(clean);
    }
    
    static bool isCleaned() {
        return field[currentY, currentX] == 2;
    }
    
    static bool findDirty() {
        for(int i = 0; i < 4; i++) {
            int x = currentX + dx[i];
            int y = currentY + dy[i];
            
            if(field[y, x] != 0) continue;
            return true;
        }
        
        return false;
    }
}
