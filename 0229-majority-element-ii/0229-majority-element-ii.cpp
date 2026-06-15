class Solution {
public:
    bool isValid(int &x, vector<int>&nums) {
        int count = 0;
        for(auto &ele:nums) {
            if(x == ele) count++;
        }
        return count > nums.size()/3;
    }
    vector<int> majorityElement(vector<int>& nums) {
        int mj1 = INT_MIN, mj2 = INT_MIN, ct1=0,ct2=0;
        for (int ele : nums) {

    if (ele == mj1) {
        ct1++;
    }
    else if (ele == mj2) {
        ct2++;
    }
    else if (ct1 == 0) {
        mj1 = ele;
        ct1 = 1;
    }
    else if (ct2 == 0) {
        mj2 = ele;
        ct2 = 1;
    }
    else {
        ct1--;
        ct2--;
    }
}
        vector<int>ans;
        if(ct1 > 0 && isValid(mj1,nums) ) ans.push_back(mj1);
        if(ct2 > 0 && isValid(mj2, nums)) ans.push_back(mj2);
        return ans;
        
    }
};