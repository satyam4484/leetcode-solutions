class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxAns = 0;
        for(auto ch: s) {
            if(count < 0) count = 0;
            maxAns = max(maxAns,count);
            if(ch == '(') count++;
            else if(ch==')') count--;
        }
        return maxAns;
    }
};