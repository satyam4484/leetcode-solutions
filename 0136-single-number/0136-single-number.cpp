class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int value = 0;
        for(auto ele: nums) {
            value^=ele;
        }
        return value;
    }
};