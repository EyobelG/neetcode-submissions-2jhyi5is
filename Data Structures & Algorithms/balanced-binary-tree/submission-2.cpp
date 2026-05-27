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
    bool isBalanced(TreeNode* root) {
        bool isbalanced;
        if (root == nullptr) {
            return true;
        }
        int leftHeight = computeNodeHeight(root->left);
        int rightHeight = computeNodeHeight(root->right);
        if (std::abs(leftHeight - rightHeight) > 1) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);

    }
private: 
    // Function to compute the height of a given node
    int computeNodeHeight(TreeNode* node) {
        // Base case: If the node is null, its height is defined as -1
        if (node == nullptr) {
            return -1;
        }

        // Recursively calculate the height of the left and right subtrees
        int leftHeight = computeNodeHeight(node->left);
        int rightHeight = computeNodeHeight(node->right);

        // The height of the current node is the maximum of its children's heights plus one
        return std::max(leftHeight, rightHeight) + 1;
    }
};
