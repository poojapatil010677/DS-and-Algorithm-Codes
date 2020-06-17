/*

Add two numbers represented by linked list

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

*/

Node* addNum(Node* first, Node* second, int carry)
{
    if(first==NULL && second==NULL && carry==0)
        return NULL;
    else if(first==NULL && second==NULL && carry==1)
    {
        Node* temp = new Node(carry);
        temp->next = NULL;
        return temp;
    }
    int sum = 0;
    if(first==NULL) sum = second->data + carry;
    else if(second==NULL) sum = first->data + carry;
    else
        sum = first->data + second->data + carry;
    if(sum>=10)
    {
        sum = sum%10;
        carry = 1;
    }
    else
    carry = 0;
    Node* temp = new Node(sum);
    if(first==NULL)
    temp->next = addNum(NULL,second->next,carry);
    else if(second==NULL)
    temp->next = addNum(first->next,NULL,carry);
    else
    temp->next = addNum(first->next,second->next,carry);
    
    return temp;
}

// write a function returns the resultant linked list
Node* addTwoLists(Node* first, Node* second) {
    // Code here
    if(first == NULL)
        return second;
    if(second == NULL)
        return first;
    
    Node* head = NULL;
    head = addNum(first,second,0);
    return head;
}


