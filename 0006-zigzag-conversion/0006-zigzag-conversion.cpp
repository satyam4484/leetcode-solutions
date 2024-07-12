class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>>ch(n);
        int l=0,i=0,flag=0;
        if(n == 1) return s;
        while(l<s.size()) {
            while(1) {
                ch[i].push_back(s[l]);
                l++;
                if(l >= s.size()) break;
                flag == 0?i++:i--;
                if(i%(n-1) == 0) flag = (flag == 1 ? 0:1);
            }
            // break;
        }
        string ans;
        for(i=0;i<n;i++) {
            ans+=string(ch[i].begin(),ch[i].end());
        }
        return ans;
    }
};