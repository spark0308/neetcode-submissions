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
    int highestPathSum = INT_MIN;

    int calculate(TreeNode* root){
        if(root == nullptr) return 0;

        int left = calculate(root->left);
        int right = calculate(root->right);

        highestPathSum = max(highestPathSum, root->val + max(left, 0) + max(right, 0));

        return max({root->val, root->val + left, root->val + right});
    }

public:
    int maxPathSum(TreeNode* root) {
        calculate(root);

        return highestPathSum;
    }
};
