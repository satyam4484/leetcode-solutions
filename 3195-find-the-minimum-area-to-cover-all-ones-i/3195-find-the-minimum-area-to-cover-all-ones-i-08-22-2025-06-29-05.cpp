class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m =grid[0].size();
        int minr=n,maxr=0;
        int minc=m,maxc=0;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    minr= min(i,minr);
                    maxr=max(i,maxr);
                    minc = min(minc,j);
                    maxc=max(maxc,j);
                }
            }
        }
        return (maxr-minr+1)*(maxc-minc+1);
    }
};