class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxans = 0;
        for(auto &ch:s) {
            if(ch =='(') {
                count++;
            }else if(ch == ')'){
                count--;
            }
            maxans = max(maxans,count);
        }
        return maxans;
    }

};