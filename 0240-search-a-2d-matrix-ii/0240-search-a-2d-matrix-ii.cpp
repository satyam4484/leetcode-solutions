class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // O(N*M), O(N*logM),
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m-1;
        while(row < n and col >= 0) {
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};