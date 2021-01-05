/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode cur = new TreeNode(0);
    public TreeNode increasingBST(TreeNode root) {
        TreeNode ans = new TreeNode(0);
        ans = cur;
        inorder(root);
        return ans.right;
    }
    
    public void inorder(TreeNode root)
    {
        if(root==null)
            return;
        inorder(root.left);
        root.left = null;
        cur.right = root;
        cur = root;
        inorder(root.right);
    }
}
