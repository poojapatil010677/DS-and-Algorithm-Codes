/*

Find a pair with given target in BST

Given a Binary Search Tree and a target sum. Check whether there's a pair 
of Nodes in the BST with value summing up to the target sum. 

Input:
2
2 1 3
5
6 5 N 3 N 1 4
2
Output:
1
0

*/

bool findPair(struct Node* root,int target,unordered_set<int>& s)
{
    if(root==NULL) return false;
    else
    {
        int rem = target-root->data;
        if(s.find(rem)!=s.end()) return true;
        s.insert(root->data);
        return findPair(root->left,target,s) || findPair(root->right,target,s);
    }
}

bool isPairPresent(struct Node *root, int target)
{
    if(root==NULL) return false;
    unordered_set<int> s;
    bool res = findPair(root,target,s);
    return res;
}
