class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=1;i<points.size();i++) {
            int xCord = abs(points[i][0]-points[i-1][0]);
            int yCord = abs(points[i][1]-points[i-1][1]);
            ans+=max(xCord,yCord);
        }
        return ans;
    }
};