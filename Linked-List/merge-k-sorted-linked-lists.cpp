/*

Merge K sorted linked lists

Given K sorted linked lists of different sizes. The task is to merge them in 
such a way that after merging they will be a single sorted linked list.

*/

Node* merge(Node* a,Node* b)
{
    if(a==NULL) return b;
    else if(b==NULL) return a;
    else
    {
        Node* temp;
        if(a->data<b->data)
        {
            temp = a;
            temp->next = merge(a->next,b);
        }
        else
        {
            temp = b;
            temp->next = merge(a,b->next);
        }
        return temp;
    }
}

Node * mergeKLists(Node *arr[], int N)
{
       if(N==1) return arr[0];
       Node* temp = arr[0];
       for(int i=1;i<N;i++)
       {
           temp = merge(temp,arr[i]);
       }
       return temp;
}


