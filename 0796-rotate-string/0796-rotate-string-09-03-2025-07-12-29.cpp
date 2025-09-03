class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++) {
            string pre = s.substr(0,i+1);
            string post = s.substr(i+1,s.size()-i-1);
            if(goal == post+pre) return true ;
        }
        return false;
    }
};