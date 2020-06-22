/*

Boundary Traversal of Binary tree

Write a function to print Boundary Traversal of a binary tree. Boundary Traversal of a binary tree here means that you have to print boundary nodes of the binary tree Anti-Clockwise starting from the root.

*/



/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

void leftside(Node* root,vector<int>& res)
{
    if(root->left==NULL && root->right==NULL) return;
    
    res.push_back(root->data);
    if(root->left)
        leftside(root->left,res);
    else
        leftside(root->right,res);
    
}

void leaves(Node* root,vector<int>& res)
{
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL)
        res.push_back(root->data);
    else
    {
        leaves(root->left,res);
        leaves(root->right,res);
    }
    
}

void rightside(Node* root,vector<int>& res)
{
     if(root->left==NULL && root->right==NULL) return;
    
    
    if(root->right)
        rightside(root->right,res);
    else
        rightside(root->left,res);
    res.push_back(root->data);
}

vector <int> printBoundary(Node *root)
{
     //Your code here
     vector<int> res;
     if(root==NULL)
        return res;
        
    res.push_back(root->data);
    if(root->left!=NULL)
        leftside(root->left,res);

     
    leaves(root,res);
    
    if(root->right!=NULL)
        rightside(root->right,res);
    
   
    return res;
}
