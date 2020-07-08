/*

Binary to BST

Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps
the original structure of Binary Tree intact.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

*/

void rearrange(Node* root,vector<int>& v)
{
    if(root==NULL) return;
    rearrange(root->right,v);
    root->data = v.back();
    v.pop_back();
    rearrange(root->left,v);
}

void inorder(Node* root, vector<int>& v)
{
    if(root==NULL) return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node *binaryTreeToBST (Node *root)
{
    if(root==NULL) return NULL;
    vector<int> v;
    inorder(root,v);
    sort(v.begin(),v.end());
    rearrange(root,v);
    return root;
}

