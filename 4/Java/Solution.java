
public class Solution {
    public int findMaxSumOfrray(int[] array) {
        if (array == null) {
            return 0;
        }
        int sum = array[0];
        int tempsum = array[0];
        for (int i = 1; i < array.length; i++) {
            tempsum = Math.max(tempsum + array[i], array[i]);
            sum = Math.max(tempsum, res);
        }
        return sum;
    }

    public static void main(String[] args) {
        int[] array = {1,-2,3,10,-4,7,2,-5};
        System.out.println(new Solution().findMaxSumOfrray(array));
    }
}
