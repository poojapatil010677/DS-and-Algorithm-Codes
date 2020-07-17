/*

Given a single linked list and an integer x. Your task is to complete the function 
deleteAllOccurances() which deletes all occurences of a key x present in the linked list. 
The function takes two arguments: the head of the linked list and an integer x.
The function should return the head of the modified linked list.


Expected Time Complexity : O(n)
Expected Auxilliary Space : O(1)

Example:
Input:
2
5
2 2 1 4 4
4
6
1 2 2 3 2 3
2

Output:
2 2 1
1 3 3

*/

Node* deleteAllOccurances(Node *head,int x)
{
    if(head==NULL) return head;
    
    Node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->next->data==x)
        {
            Node* q = temp->next;
            temp->next = temp->next->next;
            free(q);
        }
        else
        temp = temp->next;
    }
    
    temp = head;
    while(temp!=NULL && temp->data==x)
        temp = temp->next;
    head = temp;
    return head;
}

