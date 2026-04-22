class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans =0;
        int i=0;
        int j=0;
        while(j<nums.length) {
            if(nums[j] == 1) {
                j++;
            }
            else if(nums[j] == 0) {
                ans = Math.max(ans,j-i);
                while(j<nums.length && nums[j] == 0) {
                    j++;
                }
                i=j;
            }
        }
        ans = Math.max(ans,j-i);
        return ans;
        
    }
}