/*

Add one to the number represented by linked list

A number N is represented in Linked List such that each digit corresponds to a 
node in linked list. You need to add 1 to it.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Example:
Input:
4
456
123
999
1879
Output:
457 
124 
1000 
1880

*/

int addCarry(Node* head)
{
    if(head==NULL) return 1;
    
    int res = head->data + addCarry(head->next);
    head->data = (res%10);
    return (res/10);
}

Node* addOne(Node *head) 
{
    int carry = addCarry(head);
    if(carry)
    {
        Node* newhead = new Node(carry);
        newhead->next = head;
        head = newhead;
    }
    return head;
    
}
