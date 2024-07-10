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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head = new ListNode(-1);
        ListNode*tail = head;
        int r = 0;
        while(l1 or l2) {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + r;
            int val = sum%10;
            r = sum/10;
            tail->next = new ListNode(val);
            tail = tail->next;
            l1 = (l1? l1->next : nullptr);
            l2 = (l2?l2->next : nullptr);
        }

        if(r > 0){
            tail->next = new ListNode(r);
            tail = tail->next;
        }
        return head->next;
    }
};