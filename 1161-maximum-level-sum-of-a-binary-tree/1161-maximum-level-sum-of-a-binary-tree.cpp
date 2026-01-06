/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        unordered_map<int,int>mp;
        queue<TreeNode*>q;
        q.push(root);
        int level = 1;
        while(!q.empty()) {
            // iterate
            int sum = 0;

            int size = q.size();
            for(int i=0;i<size;i++) {
                auto node = q.front();
                q.pop();
                sum+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            mp[level] = sum;
            level++;
        }

        level = mp.size();
        int max_ans = INT_MIN;
        for(auto ele:mp) {
            cout<<ele.first<<" "<<ele.second<<endl;
            if(max_ans < ele.second) {
                max_ans = ele.second;
                level = ele.first;
            }else if(max_ans == ele.second) {
                level = min(level,ele.first);
            }
        }
        return level;
    }
};