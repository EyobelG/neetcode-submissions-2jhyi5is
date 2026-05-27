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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                currentLevel.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }

                if (curr->right) {
                    q.push(curr->right);
                }
            }

            res.push_back(currentLevel);
        }
        return res;        
    }
};

      
    /*
    
    // Recursively calculate the height of the left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // The height of the current node is the maximum of its children's heights plus one
    return std::max(leftDepth, rightDepth) + 1;
    */
