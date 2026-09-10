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
    int calculate(TreeNode* root, int& best) {
        if (!root) return 0;
        int left  = max(calculate(root->left,  best), 0);
        int right = max(calculate(root->right, best), 0);
        best = max(best, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int best = INT_MIN;
        calculate(root, best);
        return best;
    }
};
