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
        ListNode* dummy=new ListNode(0);
        ListNode* current = dummy;
        int carry=0;

        while(l1!=nullptr||l2!=nullptr||carry!=0){
            int x1=(l1!=nullptr)?l1->val:0;
            int x2=(l2!=nullptr)?l2->val:0;

            int sum = x1 + x2 + carry;
            carry = sum/10;
            current->next =new ListNode(sum%10);
            current=current->next;

            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        return dummy->next;
    }
};