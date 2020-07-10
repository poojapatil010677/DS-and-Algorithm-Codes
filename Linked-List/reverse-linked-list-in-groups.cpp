/*

Reverse Linked List in groups of given size

Given a linked list of size N. The task is to reverse every k nodes (where 
k is an input to the function) in the linked list.

Input:
2
8
1 2 2 4 5 6 7 8
4
5
1 2 3 4 5
3

Output:
4 2 2 1 8 7 6 5
3 2 1 5 4

*/

struct node *reverse (struct node *head, int k)
{ 
    if(head==NULL) return head;
    
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* q = NULL;
    int count = k;
    while(count-- && curr!=NULL)
    {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    head->next = reverse(q,k);
    return prev;
}

