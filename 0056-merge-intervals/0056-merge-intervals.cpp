class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int st = intervals[0][0];
        int et = intervals[0][1];
        for(int i=1;i<intervals.size();i++) {
            int curr_st = intervals[i][0];
            int curr_ed = intervals[i][1];
            if(et >= curr_st) {
                et = max(et,curr_ed);
            }else {
                ans.push_back({st,et});
                st = curr_st;
                et = curr_ed;
            }
        }
        ans.push_back({st,et});
        return ans;
    }
};