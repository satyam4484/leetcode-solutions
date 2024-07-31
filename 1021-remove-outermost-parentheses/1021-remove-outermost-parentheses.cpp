class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int i=0,j=0;
        int count = 0;
        while(j<s.size()) {
            if(s[j] == '(') {
                count++;
            }else{
                count--;
                if(count == 0) {
                    i++;
                    while(i<j){
                        ans+=s[i];
                        i++;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};