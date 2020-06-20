/*

Kth largest element in BST

Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.

Expected Time Complexity: O(H + K).
Expected Auxiliary Space: O(H).

Input:
2
4 2 9 1 3 N 10
3
9 N 10
1
Output:
4
10

*/

Node* util(Node* root,int k, int* count)
{
    if(root==NULL) return NULL;
    
    Node* r = util(root->right,k,count);
    if(r!=NULL) return r;
    
    *count = *count+1;
    if(*count==k) return root;
    
    Node* l = util(root->left,k,count);
    if(l!=NULL) return l;
}

// return the Kth largest element in the given BST rooted at 'root'
int kthLargest(Node *root, int K)
{
    //Your code here
    int count = 0;
    Node* res = util(root,K,&count);
    return res->data;
}

