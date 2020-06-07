//Covert sorted list to Binary Search Tree

/*

Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    
    TreeNode* buildTree(ListNode* head)
    {
        if(head==NULL) return NULL;
        
        ListNode* fastptr = head;
        ListNode* slowptr = head;
        ListNode* prevptr = NULL;
        
        while(fastptr!=NULL && fastptr->next!=NULL)
        {
            prevptr = slowptr;
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }
        if(prevptr!=NULL)
        prevptr->next = NULL;
        
        TreeNode* newNode = new TreeNode(slowptr->val);
        if(head==slowptr)
            return newNode;
        newNode->right = buildTree(slowptr->next);
        newNode->left = buildTree(head);
        return newNode;
        

    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        return buildTree(head);
    }
};
