class Solution {

    int[][] dir = {
        {0,1},{0,-1},{1,0},{-1,0}
    };

    void dfs(int[][] grid, int r, int c, int n, int m) {
        if(r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0) return;

        grid[r][c] = 0;

        for(int i = 0; i < 4; i++) {
            dfs(grid, r + dir[i][0], c + dir[i][1], n, m);
        }
    }

    public int numEnclaves(int[][] grid) {

        int n = grid.length;
        int m = grid[0].length;

        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) dfs(grid, i, 0, n, m);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1, n, m);
        }

        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) dfs(grid, 0, j, n, m);
            if(grid[n-1][j] == 1) dfs(grid, n-1, j, n, m);
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) count++;
            }
        }

        return count;
    }
}