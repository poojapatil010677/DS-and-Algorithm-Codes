/*

Construct a Binary Tree given its preorder and inorder traversals

ref : www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/

*/

struct Node
{
  int data;
  Node* left;
  Node* right;
};

Node* buildUtil(int* in, int* pre, int l, int r,int* index)
{
    if(l>r) return NULL;
    Node* newNode = new Node(pre[*index]);
    *index = *index + 1;
    
    if(l==r) return newNode;
    
    int i ;
    for(i=l;i<=r;i++)
    {
        if(in[i]==newNode->data)
        break;
    }
    
    newNode->left = buildUtil(in,pre,l,i-1,index);
    newNode->right = buildUtil(in,pre,i+1,r,index);
    return newNode;
}

Node* buildTree(int in[],int pre[], int n)
{
    int index = 0;
    return buildUtil(in,pre,0,n-1,&index);
}
