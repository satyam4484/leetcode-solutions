class Solution {
public:
    vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
    bool valid(int r,int c, int currVal, vector<vector<int>>&mat) {
        if (r < 0 or c < 0 or r >= mat.size() or c >= mat[0].size()) return true;
        return mat[r][c] <=  currVal;
    } 

    bool isPeakElement(int row,int col,vector<vector<int>>&mat) {
        bool peak = true;
        for(int i=0;i<4;i++) {
            if(!valid(row+dir[i][0],col+dir[i][1],mat[row][col],mat)) {
                peak = false;
                break;
            }
        }
        return peak;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(isPeakElement(i,j,mat)) return {i,j};
            }
        }

        return ans;
    }
};