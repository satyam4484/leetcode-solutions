import java.util.*;

class Solution {

    int nodes;
    int edgesCount;

    void dfs(ArrayList<Integer>[] adj, boolean[] visited, int node) {

        visited[node] = true;
        nodes++;

        edgesCount += adj[node].size();

        for (int nei : adj[node]) {
            if (!visited[nei]) {
                dfs(adj, visited, nei);
            }
        }
    }

    public int countCompleteComponents(int n, int[][] edges) {

        ArrayList<Integer>[] adj = new ArrayList[n];
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].add(v);
            adj[v].add(u);
        }

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                nodes = 0;
                edgesCount = 0;

                dfs(adj, visited, i);

                edgesCount /= 2;

                if (edgesCount == nodes * (nodes - 1) / 2)
                    count++;
            }
        }

        return count;
    }
}