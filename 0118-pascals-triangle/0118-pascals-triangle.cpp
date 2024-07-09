class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n == 1) return {{1}};
        else if (n ==2) return {{1},{1,1}};
        vector<vector<int>>v{{1},{1,1}};
        for(int i=2;i<n;i++) {
            vector<int>curr(i+1);
            curr[0] = 1;
            for(int j=1;j<i;j++) {
                curr[j] = v[i-1][j] + v[i-1][j-1];
            }
            curr[i] = 1;
            v.push_back(curr);
        }
        return v;
    }
};