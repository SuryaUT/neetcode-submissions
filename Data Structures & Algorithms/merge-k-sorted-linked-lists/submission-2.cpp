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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        
        ListNode dummy;
        ListNode* end = &dummy;
        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > minHeap;

        for(auto& node:lists){
            if(node) minHeap.push({node->val, node});
        }

        while(minHeap.size()){
            ListNode* min = minHeap.top().second;
            end->next = min;
            minHeap.pop();
            if(min->next){
                minHeap.push({min->next->val, min->next});
            }
            end = end->next;
        }

        return dummy.next;
    }
};
