public class Solution {

    public static int sum;

    public int nQueens(int n) {
        sum = 0;
        int[] cols = new int[n];
        helper(cols, n, 0);
        return sum;
    }

    private void helper(int[] cols, int n, int row) {
        if (row == n) {
            sum++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isValid(cols, row, i)) {
                cols[row] = i;
                helper(cols, n, row + 1);
            }
        }
    }

    private boolean isValid(int[] cols, int row, int col) {
        for (int i = 0; i < row; i++) {
            //不能同一列
            if (cols[i] == col) {
                return false;
            }
            //不能同一对角线，横坐标之差和纵坐标之差是不是相等
            if ((row - i) == Math.abs(col - cols[i])) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {

        System.out.println(new Solution().nQueens(8));
    }
}
