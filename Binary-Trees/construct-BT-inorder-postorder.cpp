/*

Construct a binary tree given inorder and post order traversal

*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node* buildUtil(int in[], int post[], int l,int r, int* index)
{
    if(l>r) return NULL;
    
    Node* newNode = new Node(post[*index]);
    *index = *index - 1;
    
    if(l==r) return newNode;
    
    int i;
    for(i=l;i<r;i++)
    {
        if(in[i]==newNode->data)
        break;
    }
    
    newNode->right = buildUtil(in,post,i+1,r,index);
    newNode->left = buildUtil(in,post,l,i-1,index);
    
    return newNode;
}

Node *buildTree(int in[], int post[], int n) {
    
    int index = n-1;
    return buildUtil(in,post,0,n-1,&index);
    
}

