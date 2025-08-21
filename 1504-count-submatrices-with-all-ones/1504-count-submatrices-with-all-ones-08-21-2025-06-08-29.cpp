class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> pref(m+1, vector<int>(n+1, 0));

        // build prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i-1][j-1] 
                           + pref[i-1][j] 
                           + pref[i][j-1] 
                           - pref[i-1][j-1];
            }
        }

        int count = 0;
        // enumerate all rectangles
        for (int r1 = 1; r1 <= m; r1++) {
            for (int c1 = 1; c1 <= n; c1++) {
                for (int r2 = r1; r2 <= m; r2++) {
                    for (int c2 = c1; c2 <= n; c2++) {
                        int sum = pref[r2][c2] 
                                - pref[r1-1][c2] 
                                - pref[r2][c1-1] 
                                + pref[r1-1][c1-1];
                        int area = (r2-r1+1) * (c2-c1+1);
                        if (sum == area) count++;
                    }
                }
            }
        }
        return count;
    }
};
