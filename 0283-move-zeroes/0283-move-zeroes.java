class Solution {

    public void moveZeroes(int[] nums) {
        int i=0;
        int j=0;
        while(j<nums.length) {
            if(nums[j] != 0) {
                int curr = nums[i];
                nums[i] = nums[j];
                nums[j] = curr;
                i++;
            }
            j++;
        }
    }
}