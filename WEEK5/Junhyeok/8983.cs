using System;
using System.Linq;

using static System.Console;

/*
  이 문제는 사대로부터 범위 내에 있는 동물을 찾는 것보다 동물로부터 범위 내의 사대를 찾는 방법이 좋다.
  만약 사대로부터 범위 내의 있는 동물을 찾게 된다면 탐색뿐만 아닌 중복체크도 해주어야하기 때문에 복잡해진다.
*/

class Solution_8983 {
    struct Pos {
        public int x;
        public int y;
    }
    
    static int shootCount, animalCount, distance;
    static int[] shoot;
    static Pos[] animal;

    static void Main() {
        InputData();
        Solution();
    }

    static void InputData() {
        int[] value = ReadLine().Split(' ').Select(int.Parse).ToArray();
        shootCount = value[0]; animalCount = value[1]; distance = value[2];
        shoot = ReadLine().Split(' ').Select(int.Parse).OrderBy(n => n).ToArray();
        animal = new Pos[animalCount];
        
        for(int i = 0; i < animalCount; i++) {
            int[] pos = ReadLine().Split(' ').Select(int.Parse).ToArray();
            animal[i].x = pos[0]; animal[i].y = pos[1];
        }
    }

    static void Solution() {
        int result = 0;

        for(int i = 0; i < animalCount; i++) {
            int left = 0;
            int right = shootCount - 1;
            /*
              minRange와 maxRange 는 |x - a| + b <= distance 식을 푼 결과이다.
              
              |x - a| + b <= distance
              |x - a| <= distance - b
              b - distance <= x - a <= distance - b
              
              a + b - distance <= x <= a - b + distannce
            */
            int minRange = animal[i].x + animal[i].y - distance;
            int maxRange = animal[i].x - animal[i].y + distance;

            while(left <= right) {
                int mid = (left + right) / 2;
                if(shoot[mid] >= minRange && shoot[mid] <= maxRange) {
                    result++;
                    break;
                }
                else if (shoot[mid] < minRange) left = mid + 1;
                else if (shoot[mid] > maxRange) right = mid - 1;
            }
        }

        Write(result);
    }
}
