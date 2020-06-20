/*

Lowest Common Ancestor in a BST

Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.

Expected Time Complexity: O(Height of the BST).
Expected Auxiliary Space: O(Height of the BST).

Input:
2
5 4 6 3 N N 7 N N N 8
7 8
2 1 3
1 3
Output:
7
2
*/

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL) return NULL;
   
   
   if((n1>=root->data && n2<=root->data) || (n1<=root->data && n2>=root->data))
        return root;
    
    else if(n1>root->data && n2>root->data) 
        return LCA(root->right,n1,n2);
        
    else
        return LCA(root->left,n1,n2);
}

