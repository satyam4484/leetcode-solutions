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
        // Edge case: if the list is empty or has only one node, return as is.
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Pointer to traverse the list.
        ListNode* currentNode = head;

        // Traverse the linked list.
        while (currentNode != nullptr && currentNode->next != nullptr) {
            // Calculate GCD between current node and the next node.
            int currentValue = currentNode->val;
            int nextValue = currentNode->next->val;
            int gcdValue = __gcd(currentValue, nextValue);
            
            // Create a new node with the GCD value.
            ListNode* gcdNode = new ListNode(gcdValue);
            
            // Insert the new GCD node between the current and next node.
            gcdNode->next = currentNode->next;
            currentNode->next = gcdNode;
            
            // Move the pointer to the next original node in the list.
            currentNode = gcdNode->next;
        }

        // Return the modified linked list.
        return head;
    }
};