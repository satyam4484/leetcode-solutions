class Solution {
    public int maxSubArray(int[] nums) {
        int sum  = Integer.MIN_VALUE;
        int n = nums.length;
        long currsum = 0;
        for(int i=0;i<n;i++) {
            currsum +=nums[i];
            sum = (int)Math.max(sum,currsum);
            if(currsum <0) {
                currsum = 0;
            }
        }
        return sum;
    }
}