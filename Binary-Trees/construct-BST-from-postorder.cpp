/*

Construct BST from Postorder 

Given postorder traversal of a Binary Search Tree, you need to complete the function constructTree() which will create a BST. The output will be the inorder of the constructed BST.

Input:
2
6
1 7 5 50 40 10
9
216 823 476 429 850 93 18 975 862

Output:
1 5 7 10 40 50
18 93 216 429 476 823 850 862 975

*/


/*struct Node
{
	int data;
	Node *left, *right;
};*/


Node* buildTree(int* post, int l, int r)
{
    if(l>r) return NULL;
    
    if(l==r)
    {
        Node* newNode = new Node(post[l]);
        return newNode;
    }
    
    else
    {
        Node* newNode = new Node(post[r]);
        
        int i = r-1;
        while(i>=l && post[i]>post[r])
            i--;
        
        newNode->left = buildTree(post,l,i);
        newNode->right = buildTree(post,i+1,r-1);
        return newNode;
    }
}

Node *constructTree (int post[], int size)
{
    //code here
    Node* root;
    if(size==0) return root;
    
    root = buildTree(post,0,size-1);
    return root;
}
