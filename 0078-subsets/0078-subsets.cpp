class Solution {
public:
    void solve(vector<int>&nums,vector<int>&curr, int currId, vector<vector<int>>&ans) {
        if(currId >= nums.size()) return;

        for(int i=currId;i<nums.size();i++) {
            curr.push_back(nums[i]);
            ans.push_back(curr);
            solve(nums,curr,i+1,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        ans.push_back({});
            vector<int>curr;
            solve(nums,curr,0,ans);
        return ans;
    }
};