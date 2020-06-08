/*

Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool findsum(struct TreeNode* root,int sum,int x)
{
    if(root==NULL)
        return false;
    sum = sum + root->val;
    if(root->left==NULL && root->right==NULL)
    {
        if(sum == x)
            return true;
        return false;
    }
    
    else
        return (findsum(root->left,sum,x) || findsum(root->right,sum,x));
}

bool hasPathSum(struct TreeNode* root, int sum){
    if(root==NULL)
        return false;
    return findsum(root,0,sum);
}
