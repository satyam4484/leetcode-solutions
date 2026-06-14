class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++) {
            vector<int>curr;
            for(int j=0;j<i+1;j++) {
                if(j ==0 or j == i) {
                    curr.push_back(1);
                }else{
                    int val = ans[i-1][j] + ans[i-1][j-1];
                    curr.push_back(val);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};