/*

Remove loop in linked list

You are given a linked list of N nodes. The task is to remove the loop from 
the linked list, if present.

*/


void removeLoop(Node* head)
{
    Node* fast = head;
    Node* slow = head;
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    }while(fast!=NULL && fast->next!=NULL && fast!=slow);
    if(slow==fast)
    {
        int count = 1;
        slow = slow->next;
        while(slow!=fast)
        {
            count++;
            slow = slow->next;
        }
        fast = head;
        slow = head;
        int i = 0;
        while(i<count-1)
        {
            fast = fast->next;
            i++;
        }

        while(slow!=fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}
