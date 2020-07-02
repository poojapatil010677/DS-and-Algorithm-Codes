/*

Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:
A binary tree in which the left and right subtrees of every node differ in 
height by no more than 1.

*/

class Solution {
public:
int height(struct TreeNode* root)
{
    if(root==NULL)
        return 0;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if(l>r)
            return (l+1);
        return (r+1);
    }
}

bool isBalanced(struct TreeNode* root){
    if(root==NULL)
        return true;
    else
    {
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh-rh)<=1)
            return (isBalanced(root->left) && isBalanced(root->right));
        return false;
    }
}
};
