class Solution {
public:
    int getThreshold(int mid,vector<int>&nums) {
        int count = 0;
        for(auto ele: nums) {
            count += ceil((double)(ele) / (double)(mid));
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxv = -1;
        sort(nums.begin(),nums.end());
        for(auto i: nums) {
            maxv=max(maxv,i);
        }
        int low = 1,high = maxv;
        int ans = maxv;
        while(low <= high) {
            int mid = (low + high) /2;
            int currentThreshold = getThreshold(mid,nums);
            if(currentThreshold <= threshold) {
                ans=min(ans,mid);
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};