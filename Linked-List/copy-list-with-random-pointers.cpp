/*

A linked list is given such that each node contains an additional random pointer
which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each 
node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer
points to, or null if it does not point to any node.

*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return head;
        
        Node* org = head;
        Node* copy = NULL;
        
        unordered_map<Node*,Node*> m;
        while(org)
        {
            copy = new Node(org->val);
            m[org] = copy;
            org = org->next;
        }
        
        org = head;
        
        while(org)
        {
            copy = m[org];
            copy->next = m[org->next];
            copy->random = m[org->random];
            org = org->next;
        }
        
        copy = m[head];
        return copy;
    }
}; 
