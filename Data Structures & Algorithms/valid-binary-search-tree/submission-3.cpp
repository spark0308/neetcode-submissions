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
    bool checkBST(TreeNode* node, int minRange, int maxRange){
        if(node == nullptr) return true;
        if(node->val <= minRange || maxRange <= node->val) return false;
        cout<<node->val<<endl;

        if(!checkBST(node->left, minRange, node->val)) return false;
        if(!checkBST(node->right, node->val, maxRange)) return false;

        return true;
    }

public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, INT_MIN, INT_MAX);
    }
};
