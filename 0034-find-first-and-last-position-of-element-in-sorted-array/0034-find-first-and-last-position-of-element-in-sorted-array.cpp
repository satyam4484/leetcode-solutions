class Solution {
public:
    int findFirst(vector<int>&nums,int &target) {
        int low = 0,high = nums.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(target == nums[mid]) {
                ans = mid;
                high=mid-1;
            }else if(target > nums[mid]) {
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return ans;
    }
    int findLast(vector<int>&nums,int &target) {
        int low = 0,high = nums.size()-1;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(target == nums[mid]) {
                ans = mid;
                low=mid+1;
            }else if(target > nums[mid]) {
                low = mid+1;
            }else {
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums,target),findLast(nums,target)};
    }
};