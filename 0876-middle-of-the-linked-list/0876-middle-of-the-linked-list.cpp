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
    ListNode* middleNode(ListNode* head) {
        auto *slow = head,*fast = head;
        while(true) {
            if(fast->next == nullptr) return slow;
            else if(fast->next->next == nullptr) return slow->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};