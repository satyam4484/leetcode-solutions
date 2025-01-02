class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>valid(n,0);
        for(int i=0;i<n;i++) {
            if(i!=0) valid[i] = valid[i-1];
            string s = words[i];
            if(isVowel(s[0]) and isVowel(s[s.size()-1])){
                valid[i]++;
            }
        }
        for(auto i: valid) cout<<i<<" ";

        vector<int> ans;
        for (auto query : queries) {
            int i = query[0],j=query[1];
            int currAns = valid[j]-(i-1>=0?valid[i-1]:0);
            ans.push_back(currAns);
        }
        return ans;
    }
};