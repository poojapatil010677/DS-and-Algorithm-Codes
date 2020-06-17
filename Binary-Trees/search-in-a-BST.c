/*
Search in a BST

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 
*     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root == NULL) return NULL;
    if(root->val == val) return root;
    else
    {
        if(root->val>val)
            return searchBST(root->left,val);
        else
            return searchBST(root->right,val);
    }
}
