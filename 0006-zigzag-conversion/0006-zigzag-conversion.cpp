class Solution {
public:
    string convert(string s, int n) {
        vector<vector<char>>ch(n);
        int l=0,i=0,flag=0;
        if(n == 1) return s;
        
        while(1) {
            ch[i].push_back(s[l]);
            l++;
            if(l >= s.size()) break;
            flag == 0?i++:i--;
            if(i%(n-1) == 0) flag = (flag == 1 ? 0:1);
        }
        string ans;
        for(i=0;i<n;i++) {
            ans+=string(ch[i].begin(),ch[i].end());
        }
        return ans;
    }
};