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
    void reorderList(ListNode* head) {
        ListNode* list1 = head;
        ListNode* list2;
        int length = 0;
        
        //find middle of string
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        list2 = slow->next;
        
        //reverse second half
        ListNode* prev = slow->next = nullptr;
        while(list2){
            ListNode* temp = list2->next;
            list2->next = prev;
            prev = list2;
            list2 = temp;
        }
        list2 = prev;

        //merge lists
        while(list1 && list2){
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;

            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }
    }
};
