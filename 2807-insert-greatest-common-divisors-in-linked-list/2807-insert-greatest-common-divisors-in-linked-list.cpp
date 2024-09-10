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
                int curr = temp->val;
                temp = temp->next;
                int val = __gcd(curr,temp->val);
                gcds.push_back(val);
            }else{
                break;
            }
        }
        temp = head;
        int i=0;
        while(i<gcds.size()) {
            ListNode*curr = temp->next;
            ListNode*newnode = new ListNode(gcds[i++]);
            newnode->next = curr;
            temp->next = newnode;
            temp = curr;
        }
        
        return head;
    }
};