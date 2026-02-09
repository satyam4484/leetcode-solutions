class Solution {
public:
    void createInitial(unordered_map<char,string>&mp) {
        char c ='a';
        for(char i='2';i<='9';i++) {
            int val = 3;
            if(i =='7' or i=='9') {
                val=4;
            }
            string curr;
            while(val--) {
                curr.push_back(c++);
            }
            mp[i] = curr;
        }
    }
    void solve(int i,unordered_map<char,string>&mp,string &curr,vector<string>&ans,string s) {
        if(i == s.size()) {
            ans.push_back(curr);
            return;
        }
        for(auto ch:mp[s[i]]){
            curr.push_back(ch);
            solve(i+1,mp,curr,ans,s);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        createInitial(mp);
        
        vector<string>ans;
        int i=0;
        for(auto ch:mp[digits[i]]){
            string curr;
            curr.push_back(ch);
            solve(i+1,mp,curr,ans,digits);
        }
        return ans;
        
    }
};