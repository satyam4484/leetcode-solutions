class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int ans = 0;
        int i=0,j=0;
        while(j<s.size()) {
            if(st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
            }else{
                ans=max(ans,(int)st.size());
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};