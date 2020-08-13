/*

Given a BST node, return the node which has value just greater than the given node.

Example:

Given the tree

               100
              /   \
            98    102
           /  \
         96    99
          \
           97
Given 97, you should return the node corresponding to 98 as thats the value just greater than 97 in the tree.
If there are no successor in the tree ( the value is the largest in the tree, return NULL).

Using recursion is not allowed.

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 TreeNode* Find(TreeNode* A,int B)
 {
     if(A==NULL) return NULL;
     if(A->val==B) return A;
     if(A->val<B) return Find(A->right,B);
     else return Find(A->left,B);
 }
 
 TreeNode* FindNode(TreeNode* A)
 {
     if(A==NULL) return NULL;
     while(A->left!=NULL)
        A = A->left;
    return A;
 }
 
TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    TreeNode* node = Find(A,B);
    if(node->right!=NULL)
    {
        TreeNode* temp = node->right;
        return FindNode(temp);
    }
    else
    {
        TreeNode* successor = NULL;
        TreeNode* ancestor = A;
        while(ancestor!=node)
        {
            if(node->val<ancestor->val)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor= ancestor->right;
            }
        }
        return successor;
    }
}

