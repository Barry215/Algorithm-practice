class Solution {
    public int maxSubArray(int[] nums) {
        int last_max = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.length; i++){
            if (sum > 0){
                sum += nums[i];
            }else {
                sum = nums[i];
            }
            last_max = Math.max(sum, last_max);
        }
        return last_max;
    }
}
