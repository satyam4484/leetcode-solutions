class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sorting the balloons based on their starting positions
        sort(points.begin(), points.end());
        
        // Initial arrow count is set to 1
        int count = 1;
        
        // Initializing the current arrow position to the ending position of the first balloon
        int curr = points[0][1];
        
        // Looping through the balloons starting from the second one
        for (int i = 1; i < points.size(); i++) {
            // If the current arrow position is less than the starting position of the next balloon
            if (curr < points[i][0]) {
                // Move the current arrow position to the ending position of the current balloon
                curr = points[i][1];
                // Increment arrow count as a new arrow is needed
                count++;
            } else {
                // If the current arrow position can still burst the next balloon,
                // update the current arrow position to the minimum of its current value
                // and the ending position of the current balloon
                curr = min(curr, points[i][1]);
            }
        }

        // Return the final count of arrows needed to burst all balloons
        return count;
    }
};
