/*

Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void findpath(TreeNode* root, vector<string> &paths,string s)
    {
       // char temp = (root->val);
        s = s+to_string(root->val);
        if(root->left==NULL && root->right==NULL)
        {
            paths.push_back(s);
        }
        if(root->left!=NULL)
        {
            findpath(root->left,paths,s+"->");
        }
        if(root->right!=NULL)
        {
            findpath(root->right,paths,s+"->");
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root==NULL) return paths;
        
        findpath(root,paths,"");
        return paths;
    }
};


// time complexity : O(n)
//space complexity : O(1)
