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

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int>gcds;
        ListNode*temp = head;
        while(temp) {
            if(temp->next) {
                ListNode*curr = temp->next;
                int currval = temp->val;
                int val = __gcd(currval,temp->next->val);
                ListNode*newnode = new ListNode(val);
                newnode->next = curr;
                temp->next = newnode;
                temp = curr;
            }else{
                break;
            }
        }
        // temp = head;
        // int i=0;
        // while(i<gcds.size()) {
            
            
        // }
        
        return head;
    }
};