import java.util.Arrays;

class Solution {
    public int maxFrequency(int[] nums, int k) {
        Arrays.sort(nums);

        int left = 0;
        long sum = 0;
        int maxFreq = 1;

        for (int right = 0; right < nums.length; right++) {
            sum += nums[right];

            // shrink window if cost exceeds k
            while ((long) nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }

            maxFreq = Math.max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
}