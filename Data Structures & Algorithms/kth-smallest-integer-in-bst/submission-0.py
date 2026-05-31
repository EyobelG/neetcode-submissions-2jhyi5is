# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
            stack = []
            current = root
            count = 0

            while current or stack:
                while current:
                    stack.append(current)
                    current = current.left
                current = stack.pop()
                count += 1

                if count == k:
                    return current.val
                current = current.right
            return 0





'''
        if not root:
            return 0
        numGood = 0

        stack = [(root, root.val)]

        while stack:
            node, max_so_far = stack.pop()

            if node.val >= max_so_far:
                numGood += 1
            
            current_max = max(max_so_far, node.val)

            if node.right:
                stack.append((node.right, current_max))
            if node.left:
                stack.append((node.left, current_max))
        return numGood

'''