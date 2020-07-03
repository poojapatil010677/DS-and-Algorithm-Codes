/*

Make Binary Tree From Linked List

Given a Linked List Representation of Complete Binary Tree. The task is to 
construct the Binary tree.
Note : The complete binary tree is represented as a linked list in a way 
where if root node is stored at position i, its left, and right children are 
stored at position 2*i+1, 2*i+2 respectively.

*/

// method 1 : using array

TreeNode* buildtree(vector<int> temp,int n, int i)
{
    if(i>=n) return NULL;

    TreeNode* newNode = new TreeNode(temp[i]);
    newNode->left = buildtree(temp,n,2*i+1);
    newNode->right = buildtree(temp,n,2*i+2);

    return newNode;
}

void convert(Node *head, TreeNode *&root) {
    vector<int> v;
    Node* temp = head;
    while(temp!=NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
    }
    
    int n = v.size();
    root = buildtree(v,n,0);
}

// method 2 : using queue

void convert(Node *head, TreeNode *&root) {
    queue<TreeNode*> q;
    Node* temp = head;
    if(temp!=NULL)
    {
        TreeNode * node = new TreeNode(temp->data);
        q.push(node);
        root = node;
        temp = temp->next;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(temp==NULL) break;
            TreeNode* newleft = new TreeNode(temp->data);
            curr->left = newleft;
            q.push(newleft);
            temp = temp->next;
            if(temp==NULL) break;
            TreeNode* newright = new TreeNode(temp->data);
            curr->right = newright;
            q.push(newright);
            temp = temp->next;
            
        }
    }
    
    
}

