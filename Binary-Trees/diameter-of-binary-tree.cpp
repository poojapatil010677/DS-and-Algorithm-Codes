/*

Given a Binary Tree, find diameter of it.
+The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

*/

int height(Node* root)
{
    if(root==NULL) return 0;
    
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if(l>r) return l+1;
        return r+1;
    }
}

/* Computes the diameter of binary tree with given root.  */
int diameter(Node* node) {
    // Your code here
    if(node==NULL) return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);
    int d = max(diameter(node->left),diameter(node->right));
    
    if(d>lh+rh+1) return d;
    else
        return (lh+rh+1);
    
}

