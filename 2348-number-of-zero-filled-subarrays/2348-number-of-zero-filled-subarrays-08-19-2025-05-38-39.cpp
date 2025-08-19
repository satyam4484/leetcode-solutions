class Solution {
public:
    long long getCountOfSubarray(int n) {
        return 1LL*(1LL*n*(n+1))/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0;
        for(int i=0;i<nums.size();) {
            // check for window
            int totalLength = 0;
            while(i<nums.size() and nums[i] == 0) {
                totalLength++;
                i++;
            }
            if(totalLength > 0) {
                answer = 1LL*(answer + getCountOfSubarray(totalLength));
                totalLength = 0;
            }
            while(i<nums.size() and nums[i]!=0) {
                i++;
            }

        }
        return answer;
        
    }
};