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
    ListNode* reverseLinkedList(ListNode*prev, ListNode*curr) {
        if(curr == nullptr) return prev;
        ListNode*list = reverseLinkedList(curr, curr->next);
        curr->next = prev;
        return list;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode*list = reverseLinkedList(nullptr,head);
        return list;
        
    }
};