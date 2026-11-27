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
        int carry = 0;
        ListNode* c1 = l1;
        ListNode* c2 = l2;
        ListNode dummy = ListNode();
        ListNode* temp = &dummy;

        while(c1 || c2 || carry){
            int val = carry;
            if(c1){
                val += c1->val;
                c1 = c1->next;
            } 
            if(c2){
                val += c2->val;
                c2 = c2->next;
            }
            carry = val / 10;
            val = val % 10;

            temp->next = new ListNode(val);
            temp = temp->next;
        }
        temp->next = nullptr;

        return dummy.next;
    }
};
