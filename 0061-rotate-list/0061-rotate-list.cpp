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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 or head ==nullptr) return head;
        ListNode*prev = head;
        ListNode*curr = head;
        int n = 0;
        while(curr) {
            n++;
            curr = curr->next;
        }
        k=k > 0? k%n: 0;
        k=n-k;
        curr = head;
        while(k>1) {
            curr = curr->next;
            k--;
        }

        prev = curr;
        while(prev && prev->next) {
            prev = prev->next;
        }
        prev->next = head;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};