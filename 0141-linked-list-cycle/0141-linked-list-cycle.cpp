/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head,*fast=head;
        while(slow != nullptr or fast!=nullptr) {
            slow = slow ? slow->next: nullptr;
            fast = fast ? fast->next: nullptr;
            fast = fast ? fast->next: nullptr;
            if(slow != nullptr and fast!=nullptr and slow == fast) return true;
        }
        return false;
        
    }
};