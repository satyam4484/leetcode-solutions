class Solution {
    public void reverse(int[] nums, int left, int right ){

        while(left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right]= tmp;
            left++;
            right--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,nums.length-1);
        reverse(nums,0,nums.length-1);
    }
}