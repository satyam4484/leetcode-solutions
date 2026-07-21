class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count = 0;
        string curr="";
        for(char pr: s) {
            if(pr=='(') {
                curr+=pr;
                count++;
            }else{
                count--;
                curr+=pr;
                if(count == 0) {
                    ans = ans + curr.substr(1,curr.size()-2);
                    curr = "";
                }
            }
        }
        return ans;
    }
};