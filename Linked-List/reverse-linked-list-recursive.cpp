/*

Reverse a linked list 

Given a linked list of N nodes. The task is to reverse a linked list.

*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Should reverse list and return new head.
Node* reverseList(Node *head)
{
  // Your code here
  if(head==NULL || head->next==NULL)
    return head;
    
  Node* temp = reverseList(head->next);
  head->next->next = head;
  head->next = NULL;
  return temp;
}


