class Solution {
public:
    string reverseWords(string s) {
        stringstream words(s);
        string ans="";
        string word;
        while(words >> word) {
            if(ans.size() == 0) ans = word;
            else ans = word+" "+ans;
        }
        return ans;
    }
};