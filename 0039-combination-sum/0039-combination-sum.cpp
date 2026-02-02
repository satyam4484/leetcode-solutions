class Solution {
public:

    void findAllCandidates(vector<int>&nums, int currId,vector<int>&currSub,vector<vector<int>>&ans,int &Sum) {
        if(currId >= nums.size()) {
            if(Sum == 0){
                ans.push_back(currSub);
            }
            return;
        }
        if(Sum == 0) {
            ans.push_back(currSub);
            return;
        }

        for(int i=currId;i<nums.size();i++) {
            if(Sum-nums[i] >= 0) {
                Sum-=nums[i];
                currSub.push_back(nums[i]);
                findAllCandidates(nums,i,currSub,ans,Sum);
                Sum+=nums[i];
                currSub.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        for(int i=0;i<candidates.size();i++) {
            if(candidates[i] <= target) {
                curr.push_back(candidates[i]);
                int currSum = target-candidates[i];
                findAllCandidates(candidates,i,curr,ans,currSum);
                curr.pop_back();
            }
        }

        return ans;
    }
};