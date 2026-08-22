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
    int calculateDiameter(TreeNode* root, int &diameter){
        int leftD = 0, rightD = 0;
        if(root->left != nullptr){
            leftD = 1 + calculateDiameter(root->left, diameter);
        }
        if(root->right != nullptr){
            rightD = 1 + calculateDiameter(root->right, diameter);
        }

        diameter = max(diameter, (leftD + rightD));
        return max(leftD, rightD);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        int diameter = 0;
        calculateDiameter(root, diameter);

        return diameter;
    }
};
