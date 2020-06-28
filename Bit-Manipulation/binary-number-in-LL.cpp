/*

Convert Binary NUmber in a Linked list to integer

Given head which is a reference node to a singly-linked list. 
The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

*/

    int getDecimalValue(ListNode* head) {
        unsigned int dec = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            dec = dec<<1;
            if(temp->val==1)
                dec = dec | 1;
            temp = temp->next;
        }
        return dec;
    }
