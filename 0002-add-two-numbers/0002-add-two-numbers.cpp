class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head=nullptr,*tail=nullptr;
        head = tail;
        int r = 0;
        while(l1 or l2){
            int a = l1?l1->val:0;
            int b = l2?l2->val:0;
            l1 = (l1?l1->next:nullptr);
            l2=(l2?l2->next:nullptr);
            int val = (r+a+b)%10;
            ListNode*node = new ListNode(val);
            r = (r+a+b)/10;
            if(head == nullptr) {
                head = node;
                tail=node;
            }else{
                tail->next = node;
                tail= node;
            }
        }
        if(r){
            tail->next = new ListNode(r);
        }
        return head;
    }
};