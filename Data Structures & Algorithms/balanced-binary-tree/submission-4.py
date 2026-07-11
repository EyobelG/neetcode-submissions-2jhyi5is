# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        leftHeight = self.computeNodeHeight(root.left)
        rightHeight = self.computeNodeHeight(root.right)
        if abs(leftHeight - rightHeight) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
        
    def computeNodeHeight(self, node: Optional[TreeNode]) -> int:
        if not node:
            return -1
        leftHeight = self.computeNodeHeight(node.left)
        rightHeight = self.computeNodeHeight(node.right)
        return max(leftHeight, rightHeight) + 1
        
        