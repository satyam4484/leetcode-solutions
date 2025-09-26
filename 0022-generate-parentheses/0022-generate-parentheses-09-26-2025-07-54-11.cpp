class Solution {
public:
    void getAllParenthesis(int l, int r, string &curr, vector<string>&ans) {
        if(l == 0 && r == 0) {
            ans.push_back(curr);
            return;
        }
        if(l > 0) {
            curr.push_back('(');
            getAllParenthesis(l-1, r, curr, ans);
            curr.pop_back();
        }
        if(r > l){
            curr.push_back(')');
            getAllParenthesis(l, r-1, curr, ans);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        getAllParenthesis(n, n, curr, ans);
        return ans;
    }
};
