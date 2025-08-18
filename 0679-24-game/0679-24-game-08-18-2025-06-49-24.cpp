class Solution {
public:
    const double EPS= 1e-6;
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.begin(),cards.end());
        return solve(nums);
    }

    bool solve(vector<double>&nums){
        if(nums.size() == 1 ) {
            return fabs(nums[0]-24.0) < EPS;
        }

        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums.size();j++)  {
                if(i == j) continue;

                vector<double>nextItr;
                for(int k=0;k<nums.size();k++) {
                    if(k!=i and k!=j) nextItr.push_back(nums[k]);
                }

                auto computatedValues = computeAllValues(nums[i],nums[j]);
                for(auto items: computatedValues) {
                    nextItr.push_back(items);
                    bool isValueFound = solve(nextItr);
                    if(isValueFound) return true;
                    nextItr.pop_back();

                }
            }
        }
        return false;
    }

    vector<double>computeAllValues(double a, double b) {
        vector<double>values;
        values.push_back(a+b);
        values.push_back(a-b);
        values.push_back(b-a);
        values.push_back(a*b);
        if(fabs(a) > EPS) values.push_back(b/a);
        if(fabs(b) > EPS) values.push_back(a/b);
        return values;
    }
};