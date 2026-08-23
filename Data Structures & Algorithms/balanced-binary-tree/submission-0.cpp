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
    int checkBalance(TreeNode* root, bool &balanced){
        int leftH = 1, rightH = 1;
        if(root->left != nullptr) leftH = 1 + checkBalance(root->left, balanced);
        if(root->right != nullptr) rightH = 1 + checkBalance(root->right, balanced);

        if(abs(leftH - rightH) > 1) balanced = false;

        return max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        bool balanced = true;

        checkBalance(root, balanced);

        return balanced;
    }
};
