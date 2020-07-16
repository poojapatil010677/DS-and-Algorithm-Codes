/*

Min distance between two given nodes of a binary tree

Given a binary tree and two node values your task is to find the minimum 
distance between them.

Example:
Input
1
2
1 2 3
2 3 

Output
2

*/

int distance(Node* root, int a, int level)
{
    if(root==NULL) return -1;
    if(root->data==a) return level;
    else
    {
    int l = distance(root->left,a,level+1);
    if(l!=-1) return l;
    int r = distance(root->right,a,level+1);
    if(r!=-1) return r;
    }
}

Node* LCA(Node* root, int a,int b)
{
    if(root==NULL) return NULL;
    Node* mid = NULL;
    if(root->data==a || root->data==b)
        mid = root;
    Node* left = LCA(root->left,a,b);
    Node* right = LCA(root->right,a,b);
    if((mid!=NULL && left!=NULL) || (left!=NULL && right!=NULL) || (right!=NULL && mid!=NULL))
        return root;
    else if(mid!=NULL) return mid;
    else if(left!=NULL) return left;
    else return right;
}   
int findDist(Node* root, int a, int b) {
    if(root==NULL) return 0;
    Node* lca = LCA(root,a,b);
    int d1 = distance(lca,a,0);
    int d2 = distance(lca,b,0);
    return d1+d2;
}
