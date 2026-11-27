/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy = Node(0);
        Node* temp = &dummy;
        Node* headCpy = head;
        unordered_map <Node*, Node*> mp;

        while(headCpy){
            Node* node = new Node(headCpy->val);
            mp[headCpy] = node;
            temp->next = node;
            temp = temp->next;
            headCpy = headCpy->next;
        }
        mp[nullptr] = nullptr;
        headCpy = head;
        temp = dummy.next;

        while(headCpy){
            temp->random = mp[headCpy->random];
            headCpy = headCpy->next;
            temp = temp->next;
        }

        return dummy.next;
    }
};
