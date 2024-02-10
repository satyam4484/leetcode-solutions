class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;

        for(int i=0;i<nums.size();) {
            int sum = nums[i];
            int j=i+1,k=nums.size()-1;
            while(j<k){
                bool low = false,high = false;
                if(sum + nums[j]+nums[k] == 0) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    low=true,high =true;
                }else if(sum + nums[j] + nums[k] < 0) {
                    low = true;
                }else{
                    high = true;
                }

                if(low) {
                    int x = nums[j];
                    while(j<nums.size() and x == nums[j]) j++;
                }

                if(high){
                    int x = nums[k];
                    while(k<nums.size() and x ==  nums[k]) k--;
                }
            }
            int x = nums[i];
            while(i < nums.size() and x == nums[i]) i++;
            
        }
        return ans;
    }
};