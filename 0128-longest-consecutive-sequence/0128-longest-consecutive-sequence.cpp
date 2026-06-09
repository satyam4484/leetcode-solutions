class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto i: nums){
            st.insert(i);
        }
        int ans = 0;
        for(auto ele: st) {
            if(st.find(ele-1) == st.end()) {
                int count = 1;
                int currele = ele;
                while(st.find(currele+1) != st.end()) {
                    count++;
                    currele++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};