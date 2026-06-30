class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] == nums[mid-1]) {
                if((mid-low)%2 == 0) {
                    high = mid-2;
                }else{
                    low = mid + 1;
                }
            }else if(nums[mid] == nums[mid+1]){
                if((high-mid) %2 == 0) {
                    low = mid+2;
                }else{
                    high = mid-1;
                }
            }else{
                return nums[mid];
            }
        }
        return nums[low];
    }
};