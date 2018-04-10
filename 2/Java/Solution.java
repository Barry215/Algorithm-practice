public class Solution {

    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int val) {
            this.val = val;
        }
    }

    public TreeNode reConstructBinaryTree(int[] pre, int[] in) {
        return reConstructBinaryTree(pre, 0, pre.length - 1, in, 0, in.length - 1);
    }

    private TreeNode reConstructBinaryTree(int[] pre, int startPre, int endPre, int[] in, int startIn, int endIn) {
        if (startPre > endPre || startIn > endIn) {
            return null;
        }
        TreeNode root = new TreeNode(pre[startPre]);
        for (int i = startIn; i <= endIn; i++) {
            if (in[i] == pre[startPre]) {
                root.left = reConstructBinaryTree(pre, startPre + 1, i - startIn + startPre, in, startIn, i - 1);
                root.right = reConstructBinaryTree(pre, i - startIn + startPre + 1, endPre, in, i + 1, endIn);
                break;
            }
        }
        return root;
    }

    public void printAftTree(TreeNode root){
        if (root != null){
            if (root.left != null){
                printAftTree(root.left);
            }

            if (root.right != null){
                printAftTree(root.right);
            }

            System.out.print(root.val);
        }

    }

    public static void main(String[] args) {
        int[] arr1 = {1,2,4,7,3,5,6,8};
        int[] arr2 = {4,7,2,1,5,3,8,6};

        Solution solution = new Solution();
        TreeNode treeNode = solution.reConstructBinaryTree(arr1, arr2);

        //后序遍历
        solution.printAftTree(treeNode);
    }
}
