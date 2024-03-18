class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count = 1;
        int curr=points[0][1];
        for(int i=1;i<points.size();i++) {
            if(curr < points[i][0]){
                curr = points[i][1];
                count++;
            }else{
                curr = min(curr,points[i][1]);
            }
        }

        return count;
        
    }
};