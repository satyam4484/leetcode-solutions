class Solution {

    ArrayList<ArrayList<Integer>> constructGraph(int V, int [][] edges)  {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for(int [] it: edges) {
            adj.get(it[0]).add(it[1]);
        }
        return adj;
    }

    boolean dfs(int node, ArrayList<ArrayList<Integer>> adj, 
                boolean[] visited, boolean[] pathVisited) {

        visited[node] = true;
        pathVisited[node] = true;

        for(int nei : adj.get(node)) {
            if(!visited[nei]) {
                if(dfs(nei, adj, visited, pathVisited)) {
                    return true;
                }
            } 
            else if(pathVisited[nei]) {
                return true; // cycle found
            }
        }

        pathVisited[node] = false; // backtrack
        return false;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {

        ArrayList<ArrayList<Integer>> adj = constructGraph(numCourses, prerequisites);

        boolean[] visited = new boolean[numCourses];
        boolean[] pathVisited = new boolean[numCourses];

        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited)) {
                    return false;
                }
            }
        }
        return true;
    }
}