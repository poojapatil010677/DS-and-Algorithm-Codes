// Convert Sorted Array to BST

/*
Given an array where elements are sorted in ascending order,
convert it to a height balanced BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include<stdlib.h>

struct TreeNode* buildTree(int* nums,int left, int right)
{
    if(left>right)
        return NULL;
    else
    {
        int mid = left + (right - left) / 2 ;
        struct TreeNode* newnode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newnode->val = nums[mid];
        newnode->left = buildTree(nums,left,mid-1);
        newnode->right = buildTree(nums,mid+1,right);
        return newnode;
    }
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(nums == NULL)
        return NULL;
    return buildTree(nums,0,numsSize-1);
}
