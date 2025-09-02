class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        for(int i=num.size()-1;i>=0;) {
            if((num[i]-'0')&1) {
                while(i>=0) {
                    ans+=num[i];
                    i--;
                }
            }
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};