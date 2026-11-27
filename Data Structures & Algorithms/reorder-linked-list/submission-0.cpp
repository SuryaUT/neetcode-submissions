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
        ListNode* list2 = head;
        int length = 0;
        
        //find middle of string
        while(list2){
            list2 = list2->next;
            length++;
        }
        
        int mid = (length + 1)/2;
        list2 = head;
        while(mid > 0){
            list2 = list2->next;
            mid--;
        }

        //reverse second half
        ListNode* prev = nullptr;
        while(list2){
            ListNode* temp = list2->next;
            list2->next = prev;
            prev = list2;
            list2 = temp;
        }
        list2 = prev;

        //
        while(list1 && list2){
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;

            list1->next = list2;
            list2->next = temp1;
            list1 = temp1;
            list2 = temp2;
        }

        list1->next = nullptr;
    }
};
