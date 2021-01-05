/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    if root == nil{
        return 0
    }
    
    if root.Left == nil && root.Right == nil {
        return 1
    } else {
        l := maxDepth(root.Left)
        r := maxDepth(root.Right)
        if l>r {
            return int(l+1)
        } else {
            return int(r+1)
        }
        
    }
}
