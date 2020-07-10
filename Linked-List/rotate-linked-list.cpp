/*

Rotate linked list

Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, where k is a given positive integer smaller 
than or equal to length of the linked list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Input:
2
8
1 2 3 4 5 6 7 8
4
5
2 4 7 8 9
3
Output:
5 6 7 8 1 2 3 4
8 9 2 4 7

*/

Node* rotate(Node* head, int k)
{
    Node* prev = NULL;
    Node* curr = head;
    int i=0;
    while(curr!=NULL && i!=k)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    if(curr!=NULL)
    {
        prev->next = NULL;
        prev = head;
        head = curr;
        while(curr->next!=NULL)
            curr = curr->next;
        curr->next = prev;
    }
    return head;
}

