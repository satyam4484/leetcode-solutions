class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j] == 1) {
                    int left = matrix[i][j-1];
                    int top = matrix[i-1][j];
                    int dig = matrix[i-1][j-1];
                    matrix[i][j]+=min({left,top,dig});
                }
            }
        }

        int count = 0;
        for(auto row:matrix) {
            for(auto ele:row) {
                count+=ele;
            }
        }
        return count;
        
    }
};