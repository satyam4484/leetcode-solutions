class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0, right = 0;
        int currCount = 0;
        string ans="";
        while(right<s.size()) {
            if(s[right] == '(') {
                currCount++;
            }else{
                currCount--;
                if(currCount == 0) {
                    left++;
                    while(left<right) {
                        ans+=s[left];
                        left++;
                    }
                    left++;
                }
            }
            right++;
        }
        return ans;
    }
};