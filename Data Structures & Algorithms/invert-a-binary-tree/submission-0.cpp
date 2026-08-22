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
    TreeNode* swapNodesRec(TreeNode* root){
        if(root->left != nullptr)
            root->left = swapNodesRec(root->left);
        if(root->right != nullptr)
            root->right = swapNodesRec(root->right);
        
        TreeNode* tempNode = root->left;
        root->left = root->right;
        root->right = tempNode;
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        swapNodesRec(root);

        return root;
    }
};
