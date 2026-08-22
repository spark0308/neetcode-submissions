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
    void calculateDepth(TreeNode* root, int depth, int &maxDepth){
        if(maxDepth < depth) maxDepth = depth;
        depth++;
        if(root->left != nullptr) calculateDepth(root->left, depth, maxDepth);
        if(root->right != nullptr) calculateDepth(root->right, depth, maxDepth);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int maxDepth = 0;
        calculateDepth(root, 1, maxDepth);

        return maxDepth;
    }
};
