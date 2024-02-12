class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int count = 0;
        for(int i=0;i<s.size();i++) {
            int curr = 0;
            unordered_set<char>st;
            int j=i;
            while(j<s.size()) {
                if(st.find(s[j]) == st.end()) {
                    st.insert(s[j]);
                    curr++;
                    j++;
                }else{
                    break;
                }
            }
            count = max(count,curr);
        }
        return count;
    }
};