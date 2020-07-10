/*

Merge sorted Linked list

Given two sorted linked lists consisting of N and M nodes respectively. 
The task is to merge both of the list (in-place) and return head of the merged
list.
Note: It is strongly recommended to do merging in-place using O(1) extra space.

Input:
2
4 3
5 10 15 40 
2 3 20
2 2
1 1
2 4 
Output:
2 3 5 10 15 20 40
1 1 2 4

*/

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    if(head_A==NULL) return head_B;
    
    if(head_B==NULL) return head_A;
    
    else
    {
        Node* result = NULL;
        if(head_A->data<=head_B->data)
        {
            result = head_A;
            result->next = sortedMerge(head_A->next,head_B);
        }
        else
        {
            result = head_B;
            result->next = sortedMerge(head_A,head_B->next);
        }
        return result;
    }
}  
