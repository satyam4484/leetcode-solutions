class Solution {

    int[][] dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

    boolean valid(int x,int y, char [][] board, int n, int m ) {
        return (x>=0 && y>=0 && x<n && y <m && board[x][y] == 'O');
    }
    void dfs(char [][] board, int r, int c, int n, int m) {
        board[r][c] = '$';
        for(int i=0;i<4;i++) {
            int x = dir[i][0] + r;
            int y = dir[i][1] + c;
            if(valid(x,y,board,n,m)) {
                dfs(board,x,y,n,m);
            }
        }


    }
    public void solve(char[][] board) {
        int n = board.length;
        int m =board[0].length;

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((i==0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    dfs(board,i,j,n,m);

                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == '$') {
                    board[i][j] = 'O';
                }else {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
}