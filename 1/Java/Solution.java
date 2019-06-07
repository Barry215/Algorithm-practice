public class Solution {
    public boolean Find(int target, int[][] array) {
        int breakPoint = array[0].length;

        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < breakPoint; j++) {
                if (array[i][j] == target) {
                    return true;
                }

                if (array[i][j] > target) {
                    breakPoint = j;
                    break;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] array = { { 1, 2, 3, 4, 5 }, { 2, 4, 6, 8, 10 }, { 3, 6, 9, 12, 15 } };

        System.out.println(solution.Find(10, array));
    }
}
