class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        ans.reserve(n*m);
        for (int d = 0; d < m + n - 1; d++) {
            vector<int>curr;
            int r = (d < m) ? 0 : d - m + 1;
            int c = (d < m) ? d : m - 1;
            while(r<n and c>=0) {
                curr.push_back(mat[r][c]);
                r++,c--;
            }
            if(d%2 == 0) {
                reverse(curr.begin(),curr.end());
            }
            ans.insert(ans.end(), curr.begin(), curr.end());
        }
        return ans;
    }
};