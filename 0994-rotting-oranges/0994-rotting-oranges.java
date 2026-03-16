import java.util.*;

class Solution {

    class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    public boolean isValid(int r, int c, int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        return (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] == 1);
    }

    public int orangesRotting(int[][] grid) {

        Queue<Pair> q = new LinkedList<>();
        int fresh = 0;
        int minutes = 0;

        // Step 1: Add all rotten oranges to queue
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {

                if (grid[i][j] == 2) {
                    q.add(new Pair(i, j));
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0) return 0;

        int[][] dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        // Step 2: BFS
        while (!q.isEmpty()) {

            int size = q.size();
            boolean rottedThisRound = false;

            for (int i = 0; i < size; i++) {

                Pair curr = q.poll();
                int x = curr.first;
                int y = curr.second;

                for (int[] d : dir) {

                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (isValid(nx, ny, grid)) {

                        grid[nx][ny] = 2;
                        fresh--;
                        q.add(new Pair(nx, ny));
                        rottedThisRound = true;
                    }
                }
            }

            if (rottedThisRound) minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
}