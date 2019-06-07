public class Solution {
    public int find(int m, int[] arr) {
        int i = 0;
        int j = arr.length - 1;
        int res = 0;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum > m) {
                j--;
            } else if (sum < m) {
                i++;
            } else {
                res++;
                i++;
                j--;
            }
        }
        return res;
    }

    public static void main(String[] args) {

        int[] arr = {1, 3, 5, 6, 8, 13, 16};
        
        System.out.println(new Solution().find(14, arr));
    }
}
