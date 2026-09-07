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
    ListNode*reverseList(ListNode*head) {
        ListNode*prev = nullptr,*curr= head;
        while(curr !=nullptr) {
            ListNode*nextptr = curr ? curr->next: nullptr;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half
        ListNode*reversedList = reverseList(slow->next);
        ListNode*temp = reversedList;
        slow = head;
        while(temp !=nullptr) {
            if(slow -> val != temp->val) return false;
            slow = slow->next;
            temp = temp->next;
        }

        return true;

    }
};