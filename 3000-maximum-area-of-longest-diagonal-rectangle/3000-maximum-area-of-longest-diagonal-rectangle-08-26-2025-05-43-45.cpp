class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int maxDiag = 0;  // store diagonal squared

        for (auto &rect : dimensions) {
            int a = rect[0], b = rect[1];
            int diagSq = a * a + b * b;   // squared diagonal
            int area = a * b;

            if (diagSq > maxDiag) {
                maxDiag = diagSq;   // found longer diagonal
                ans = area;
            } else if (diagSq == maxDiag) {
                ans = max(ans, area); // tie → take bigger area
            }
        }
        return ans;
    }
};
