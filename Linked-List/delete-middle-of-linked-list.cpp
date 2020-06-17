/*

Given a singly linked list, delete middle of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.
If the input linked list is NULL or has 1 node, then it should return NULL

*/

// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node* head) {
    // Your Code Here
    if(head==NULL || head->next==NULL) return head;
    
    Node* slowptr = head;
    Node* fastptr = head;
    while(fastptr!=NULL && fastptr->next!=NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }
    if(slowptr->next!=NULL)
    {
        slowptr->data = slowptr->next->data;
        slowptr->next = slowptr->next->next;
    }
    else
    {
        head->next = NULL;
    }
    return head;
}
