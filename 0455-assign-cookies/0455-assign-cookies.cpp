
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; // Child pointer
        int j = 0; // Cookie pointer

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; // Child is satisfied
            }
            j++; // Use this cookie and move forward
        }

        return i;
    }
};
