import java.util.ArrayList;
import java.util.List;

public class Solution {
    public int getResult(int n, int m) {
        List<Integer> start = new ArrayList<Integer>();
        for (int i = 1; i <= n; i++) {
            start.add(i);
        }
        //从下标为K开始计数  
        int k = 0;
        while (start.size() > 1) {
            //第m人的索引位置
            k = (k + m) % (start.size()) - 1;
            // 判断是否到队尾  到队尾时候k=-1
            if (k < 0) {
                start.remove(start.size() - 1);
                k = 0;
            } else {
                start.remove(k);
            }
        }
        return start.get(0);
    }

    public static void main(String[] args) {
        System.out.println(new Solution().getResult(5, 3));
    }
}
