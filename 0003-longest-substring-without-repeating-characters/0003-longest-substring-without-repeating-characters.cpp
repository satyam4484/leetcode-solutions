class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>mp;
        int ans = 0;
        int i=0,j=0;
        while(j<s.size()) {
            if(mp.find(s[j]) == mp.end())  {
                mp.insert(s[j]);
                j++;
            }
            else{
                ans = max(ans,j-i);
                mp.erase(s[i]);
                i++;
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};