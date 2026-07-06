class Solution {
public:
    bool isElementPresent(vector<int>& nums, int ele) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == ele)
                return true;
            else if (nums[mid] < ele)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }

    int findKthPositive(vector<int>& arr, int k) {

        int maxEle = arr.back();

        vector<int> missing;

        for (int i = 1; i <= maxEle; i++) {
            if (!isElementPresent(arr, i))
                missing.push_back(i);
        }

        if (missing.size() >= k)
            return missing[k - 1];

        return maxEle + (k - missing.size());
    }
};