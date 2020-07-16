/*

Given a linked list, you have to perform the following task:

Extract the alternative nodes from starting from second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.

Input:
2
8
10 4 9 1 3 5 9 4
5
1 2 3 4 5

Output:
10 9 3 9 4 5 1 4
1 3 5 4 2 

*/

Node* reverse(Node* head)
{
    if(head==NULL) return head;
    Node* curr = head;
    Node* prev = NULL;
    Node* q = NULL;
    while(curr!=NULL)
    {
        q = curr->next;
        curr->next = prev;
        prev = curr;
        curr = q;
    }
    return prev;
}

void rearrange(struct Node *head)
{
    if(head==NULL || head->next==NULL) return;
    
    Node* odd = head;
    Node* even = head->next;
    Node* even_head = head->next;
    
    while(even!=NULL && even->next!=NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    
    odd->next = reverse(even_head);
}
