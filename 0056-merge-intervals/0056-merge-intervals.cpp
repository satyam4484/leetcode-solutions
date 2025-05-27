class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int st = intervals[0][0];
        int ed = intervals[0][1];
        for(int i=1;i<intervals.size();i++) {
            if(ed >= intervals[i][0]) {
                ed = max(ed,intervals[i][1]);
            }else{
                ans.push_back({st,ed});
                st=intervals[i][0];
                ed=intervals[i][1];
            }
        }
        ans.push_back({st,ed});
        return ans;
    }
};