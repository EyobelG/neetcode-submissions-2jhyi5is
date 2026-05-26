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
// diameter = length of the LONGEST path between any two nodes within thetree.
using namespace std;
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        getHeight(root);
        return maxDiameter;        
    }
private:
    int maxDiameter = 0;
    int getHeight(TreeNode* root) {
        // Base Case: An empty tree has height -1 (edges convention)
        // If you prefer counting nodes, return 0 here instead.
        if (!root) {
            return 0; 
        }

        // Recursively find the height of left and right subtrees
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Height of current node is 1 + max height of subtrees
        return 1 + max(leftHeight, rightHeight);
    }
};


/*

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
        
    }
};

*/