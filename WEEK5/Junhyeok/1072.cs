using System;
using System.Linq;

class Solution_1072 {
    static void Main() {
        long x, y, z; // 100,000,000 * 100 = 10,000,000,000 이므로 long 타입으로 선언
        int[] value = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
        x = value[0]; y = value[1];
        z = y * 100 / x;

        if(z >= 99) {
            Console.Write(-1);
            return;
        }

        long left = 0;
        long right = x;

        while(left <= right) {
            var mid = (left + right) / 2;
            var rate = ((mid + y) * 100) / (mid + x); // mid 수만큼 게임을 했을 때 승률 가져오기

            /*
                승률이 다르다는 것은 이 판수보다 미만으로 했을 때도 바뀔 가능성이 있으므로
                right = mid - 1 로 범위 줄이기
            */
            if(rate != z) right = mid - 1;
            else left = mid + 1;
        }
        
        Console.Write(left);
    }
}
