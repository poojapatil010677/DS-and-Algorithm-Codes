/*

Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

*/

Node *sortedInsert(Node* head, int x)
{
   //Your code here
   if(head==NULL)
    return head;
    
    //insert at the beginning
    if(x<head->data)
    {
        Node* temp = head;
        while(temp->next!=head)
            temp = temp->next;
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        temp->next = head;
        return head;
    }
    else
    {
        Node* temp = head->next;
        Node* prev = head;
        while(temp!=head && temp->data<x)
        {
            prev = temp;
            temp = temp->next;
        }
        
        Node* newNode = new Node(x);
        newNode->next = temp;
        prev->next = newNode;
        return head;
    }
}
