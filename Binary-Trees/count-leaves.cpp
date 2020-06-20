/*

count leaves in Binary tree

Given a Binary Tree of size N , You have to count leaves in it.

*/

int countLeaves(Node* root)
{
  // Your code here
  if(root==NULL) return 0;
  
  if(root->left==NULL && root->right==NULL)
    return 1;
    
    return countLeaves(root->left)+countLeaves(root->right);
}

