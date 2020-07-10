/*

Flattening a linked list

Given a Linked List of size N, where every node represents a linked list and 
contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which should be sorted.

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
And after flattening the above list, the sorted linked list looks like:

 5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: The flattened list will be printed using the bottom pointer instead of 
next pointer.

*/

Node* merge(Node* a, Node* b)
{
    if(a==NULL) return b;
    
    if(b==NULL) return a;
    
    Node* result;
    
    if(a->data<b->data)
    {
        result = a;
        result->bottom = merge(a->bottom,b);
    }
    else
    {
        result = b;
        result->bottom = merge(a,b->bottom);
    }
    return result;
}

Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
        return root;
    
    root->next = flatten(root->next);
    return merge(root,root->next);
}


