class Solution {
    void reverse(int[] nums, int i,int j) {
        while(i<j) {
            int curr = nums[i];
            nums[i] = nums[j];
            nums[j] = curr;
            i++;
            j--;
        }
    }
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
}