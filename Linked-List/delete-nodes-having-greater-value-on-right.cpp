/*

Given a singly linked list, remove all the nodes which have a greater value 
on its next adjacent element.

Input:
3
8
12 15 10 11 5 6 2 3
6
10 20 30 40 50 60
6
60 50 40 30 20 10

Output:
15 11 6 3
60
60 50 40 30 20 10

*/

Node *compute(Node *head)
{
    if(head->next==NULL) return head;
    head->next = compute(head->next);
    Node* temp = head;
    while(temp->next!=NULL)
    {
        if(temp->next->data>temp->data)
        {
            Node* q = temp->next;
            temp->data = temp->next->data;
            temp->next = temp->next->next;
            free(q);
        }
        else
        temp = temp->next;
    }
    return head;
}

