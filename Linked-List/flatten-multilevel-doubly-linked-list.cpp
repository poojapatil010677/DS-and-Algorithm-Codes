/*

You are given a doubly linked list which in addition to the next and previous 
pointers, it could have a child pointer, which may or may not point to a separate 
doubly linked list. These child lists may have one or more children of their 
own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked 
list. You are given the head of the first level of the list.

Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        //if(head==NULL || head->next==NULL) return head;
        
        Node* curr = head;
        Node* tail = NULL;
        Node* temp = NULL;
        while(curr!=NULL)
        {
            tail = curr->next;
            if(curr->child!=NULL)
            {
               // tail = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                temp = curr->next;
                while(temp->next!=NULL)
                    temp = temp->next;
                temp->next = tail;
                if(tail!=NULL)
                    tail->prev = temp;
            }
            curr->child = NULL;
            curr = tail;
        }
        return head;
    }
};
