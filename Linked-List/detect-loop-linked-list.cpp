/*

Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

int detectloop(Node *head) {

    // your code here
    if(head==NULL) return 0;
    Node* slwptr = head;
    Node* fstptr = head->next;
    while(fstptr!=NULL && fstptr->next!=NULL)
    {
        if(fstptr==slwptr)
            return 1;
        fstptr = fstptr->next->next;
        slwptr = slwptr->next;
    }
    return 0;
}

