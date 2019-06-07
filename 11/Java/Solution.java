import java.util.Scanner;

/*最大公约数是x0，所以设这两个数为x0*k1 , x0*k2 (其中k1,k2互质）。
 由题意得：x0 * k1 * k2 = y0,所以 k1*k2 = y0 / x0 (当然如果y0 / x0 除不尽的话,当然没答案啦（输出0)
 然后只要穷举k1,k2 的值，因为 k1*k2 = y0 / x0 是轮换式,所以不妨设 k1 < k2 , 然后从1 ~ floor（sqrt(y0 / x0)）穷举
 如果k1， k2 互质 ， 那么就找到 2 组解了 ， 所以 sum += 2 。 
 */

public class Solution {

    public static int count(int n, int m) {
        if (n > m || m % n != 0) {
            System.out.println("不存在这样的两个数，使得最大公约数是n, 最小公倍数是m");
            return 0;
        }

        int count = 0;
        int xy = m / n;
        for (int i = 1; i <= Math.floor(Math.sqrt(xy)); i++) {
            if (xy % i == 0) {
                int j = xy / i;
                //判断是否互质
                if ((i > j ? i % j : j % i) != 0 || i == 1) {
                    System.out.println("找到两对：" + i * n + "," + j * n + " " + j * n + "," + i * n);
                    count++;
                }
            }
        }

        if (count == 0) {
            System.out.println("不存在这样的两个数，使得最大公约数是n, 最小公倍数是m");
        }

        return 2 * count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入最大公约数：");
        int n = sc.nextInt();
        System.out.println("请输入最小公倍数：");
        int m = sc.nextInt();

        System.out.println(count(n, m));
        
    }

    

}