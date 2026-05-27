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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* prev = nullptr; // Keeps track of the last node we processed

        while (curr != nullptr || !st.empty()) {
            // 1. Go as far left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // 2. Process the bottom-most/left-most node
            curr = st.top();
            st.pop();
            
            // 3. The core BST rule: The sequence must be strictly increasing.
            // If the previous node's value is >= current, the BST is invalid.
            if (prev != nullptr && prev->val >= curr->val) {
                return false;
            }
            
            // Update 'prev' to the current node before moving on
            prev = curr;
            
            // 4. Move to the right subtree
            curr = curr->right;
        }
        
        return true;
    }
};

