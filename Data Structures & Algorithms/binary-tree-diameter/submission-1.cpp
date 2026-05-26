class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // 1. Fast I/O optimization to unsync C++ and C streams
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        maxDiameter = 0; 
        getHeight(root);
        return maxDiameter;
    }

private:
    int maxDiameter = 0;

    // 2. Pass by pointer is fine, but we can keep the memory footprint low
    int getHeight(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};