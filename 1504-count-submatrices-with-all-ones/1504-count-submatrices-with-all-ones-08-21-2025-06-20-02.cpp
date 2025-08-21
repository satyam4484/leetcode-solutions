class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        int count = 0;

        for (int i = 0; i < m; i++) {
            // update histogram heights
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            // count rectangles ending at row i
            for (int j = 0; j < n; j++) {
                int minHeight = INT_MAX;
                for (int k = j; k >= 0; k--) {
                    minHeight = min(minHeight, height[k]);
                    if (minHeight == 0) break; // optimization
                    count += minHeight;
                }
            }
        }

        return count;
    }
};
