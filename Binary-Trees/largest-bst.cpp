/*

Largest BST

Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the BST).

Input
2
1 4 4 6 8
6 6 3 N 2 9 3 N 8 8 2

Output
1
2

*/

struct Info
{
    int ans;
    int max;
    int min;
    bool isBST;
};

Info Utilbst(Node* root)
{
    if(root==NULL)
        return {0,INT_MIN,INT_MAX,true};
    if(root->left==NULL && root->right==NULL)
        return {1,root->data,root->data,true};
        
    Info l = Utilbst(root->left);
    Info r = Utilbst(root->right);
    
    Info res;
    res.max = max(root->data,max(l.max,r.max));
    res.min = min(root->data,min(l.min,r.min));
    if(l.isBST && r.isBST && root->data>l.max && root->data<r.min)
    {
        res.ans = l.ans + r.ans + 1;
        res.isBST = true;
        return res;
    }
    
    res.ans = max(l.ans,r.ans);
    res.isBST = false;
    return res;
}

int largestBst(Node *root)
{
	if(root==NULL) return 0;
	int res = Utilbst(root).ans;
	return res;
}

