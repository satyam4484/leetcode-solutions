class Solution {
public:
    long long  getCount(int n) {
        return 1LL*(1LL*n*(n+1))/2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {

        long long ans = 0;
        for(int i=0;i<nums.size();) {

            // winfow lenght
            int window = 0;
            while(i<nums.size() and nums[i] == 0) {
                window++;
                i++;
            }
            if(window > 0) {
                ans = 1LL*(ans+getCount(window));
                window = 0;
            }

            while(i<nums.size() and nums[i] != 0) {
                i++;
            }
        }
        return ans;
        
    }
};