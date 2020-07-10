/*

Intersection point in Y shaped linked list

Given two singly linked lists of size N and M, write a program to get the 
point where two linked lists intersect each other.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)

*/

int intersectPoint(Node* head1, Node* head2)
{
    if(head1==NULL) return -1;
    if(head2==NULL) return -1;
    else
    {
        int n1 = 0;
        int n2 = 0;
        Node* temp = NULL;
        
        temp = head1;
        while(temp!=NULL)
        {
            n1++;
            temp = temp->next;
        }
        
        temp = head2;
        while(temp!=NULL)
        {
            n2++;
            temp = temp->next;
        }
        temp = NULL;
        Node* temp2 = NULL;
        if(n1>n2)
        {
            temp2 = head2;
            temp = head1;
            int i = 0;
            while(i<(n1-n2))
            {
                i++;
                temp = temp->next;
            }
        }
        
        else if(n2>n1)
        {
            temp = head1;
            temp2 = head2;
            int i=0;
            while(i<(n2-n1))
            {
                i++;
                temp2 = temp2->next;
            }
        }
        else
        {
            temp = head1;
            temp2 = head2;
        }
        
        while(temp!=NULL && temp2!=NULL && temp!=temp2)
        {
            temp = temp->next;
            temp2 = temp2->next;
        }
        if(temp!=temp2) return -1;
        return temp->data;
    
    }
    
}
