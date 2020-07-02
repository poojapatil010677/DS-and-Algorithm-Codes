/*

Subtree of Another tree

Given two non-empty binary trees s and t, check whether tree t has exactly the 
same structure and node values with a subtree of s. A subtree of s is a tree 
consists of a node in s and all of this node's descendants. The tree s could 
also be considered as a subtree of itself.

*/

class Solution {
public:
    
    bool subUtil(TreeNode* s, TreeNode* t)
    {
        if(s==NULL && t==NULL) return true;
        if(s==NULL || t==NULL) return false;
        
        return (s->val==t->val && subUtil(s->left,t->left) && subUtil(s->right,t->right));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t==NULL) return true;
        if(s==NULL) return false;
        
        if(subUtil(s,t))
            return true;
        return (isSubtree(s->left,t) || isSubtree(s->right,t));
    }
};
