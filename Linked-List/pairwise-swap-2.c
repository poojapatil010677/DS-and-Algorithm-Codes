/*

swap nodes in pairs

Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

*/

struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL || head->next==NULL) return head;
    
    struct ListNode* remain = head->next->next;
    
    struct ListNode* newHead = head->next;
    
    head->next->next = head;
    head->next = swapPairs(remain);
    return newHead;
}
