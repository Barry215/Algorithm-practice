
public class Solution {
    //利用快排思想，O(n)得到数组中位数
    public int moreThanHalfNum_Solution(int[] array) {
        int index = 0;
        int start = 0;
        int end = array.length - 1;
        int middle = array.length / 2;
        index = partition(array, start, end); 
        while(index != middle){
            if (index > middle) {
                end = index - 1;
                index = partition(array, start, end);
            } else {
                start = index + 1;
                index = partition(array, start, end);
            }
        }

        return checkMoreThanHalf(array, array[middle]) ? array[middle] : 0;
    }

    public int partition(int[] array, int start, int end){
        int key = array[start];
        while(start<end){
            while(start < end && key <= array[end]){
                end--;
            }
            array[start] = array[end];
            while(start < end && key >= array[start]){
                start++;
            }
            array[end] = array[start];
        }
        array[start] = key;
        return start;
    }

    boolean checkMoreThanHalf(int[] array, int val){
        int count = 0;
        for (int i = 0; i < array.length; i++){
            if (array[i] == val){
                count++;
            }
        }
        
        return count * 2 > array.length;
    }

    public static void main(String[] args) {
        int[] array = {1,2,3,2,2,2,5,4,2};
        Solution solution = new Solution();

        System.out.println(solution.moreThanHalfNum_Solution(array));
    }
}
