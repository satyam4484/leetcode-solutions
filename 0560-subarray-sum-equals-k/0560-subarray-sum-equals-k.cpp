class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans = 0;
        mp[0]=1;
        long long int sum = 0;
        for(auto ele: nums) {
            sum+=ele;
            if(mp.find(sum-k) != mp.end()) {
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};