/*

Right view of binary tree

Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

*/

int height(Node* root)
{
    if(root==NULL) return 0;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if(l>r) return l+1;
        else
            return r+1;
    }
}

void rightViewUtil(Node* root,int i,int* right)
{
    if(root==NULL) return;
    
    if(i==1 && *right==0)
    {
        cout<<root->data<<' ';
        *right=1;
    }
    else
    {
        rightViewUtil(root->right,i-1,right);
        rightViewUtil(root->left,i-1,right);
    }
}

// Should print right view of tree
void rightView(Node *root)
{
   // Your Code here
   int h = height(root);
   for(int i=1;i<=h;i++)
   {
       int right = 0;
       rightViewUtil(root,i,&right);
   }
}


