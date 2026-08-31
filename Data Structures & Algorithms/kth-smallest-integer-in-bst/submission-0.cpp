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
    vector<int> sortedElements;
    void getSortedElements(TreeNode* root){
        if(root->left) getSortedElements(root->left);

        sortedElements.push_back(root->val);

        if(root->right) getSortedElements(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        getSortedElements(root);

        return sortedElements[k-1];
    }
};
