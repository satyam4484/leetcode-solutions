/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        int l=0,up=0,r=n-1,d=m-1;
        vector<vector<int>>v(m,vector<int>(n,-1));
        while(true) {

            // l - r
            bool flag = true;
            for(int i=l;i<=r;i++) {
                if(head != nullptr){
                    cout<<"head->val -- "<<up<<" "<<i<<" "<<r<<" "<<head->val<<endl;
                    v[up][i] = head->val;
                    cout<<"v--"<<v[up][i]<<endl;
                    head = head->next;
                }else{
                    flag = false;
                }
            }

            if(not flag) break;
            // up+1 - d
            for(int i=up+1;i<=d;i++) {
                if(head != nullptr){
                    v[i][r] = head->val;
                    head = head->next;
                }else{
                    flag = false;
                }
            }
            
            if(not flag) break;
            // r-1 -- l
            for(int i=r-1;i>=l;i--){ 
                if(head != nullptr){
                    v[d][i] = head->val;
                    head = head->next;
                }else{
                    flag = false;
                }
            }

            if(not flag) break;
            // d-1 -- up+1
            for(int i=d-1;i>up;i--) {
                if(head != nullptr){
                    v[i][l] = head->val;
                    head = head->next;
                }else{
                    flag = false;
                }
            }
            l++,up++,r--,d--;
            if(l > r or up > d) break;
            if(not flag) break;
        }
        return v;
    }
};