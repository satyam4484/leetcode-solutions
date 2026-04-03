class Solution {
    int [][] dir  = {
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };

    boolean valid(int r,int c, char[][] grid,int n, int m) {
        return (r>=0 && c>=0 && r<n &&  c< m && grid[r][c] =='1');
    }
    void dfs(int r,int c, char[][] grid, int n,int m) {
        grid[r][c] = '0';
        for(int i=0;i<4;i++) {
            int x = r+dir[i][0];
            int y = c + dir[i][1];
            if(valid(x,y,grid,n,m)) {
                dfs(x,y,grid,n,m);
            }
        }
    }
    public int numIslands(char[][] grid) {

    int n = grid.length;
    int m = grid[0].length;
    int count = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '1'){
                dfs(i,j,grid,n,m);
                count++;
            }
        }
    }
    return count;
        
    }
}