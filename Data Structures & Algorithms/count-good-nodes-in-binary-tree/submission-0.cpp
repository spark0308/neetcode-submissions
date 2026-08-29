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
    int ans = 0;
    void findGoodNodes(TreeNode* root, int latestGreatestNodeValue){
        if(root == nullptr) return;

        if(root->val >= latestGreatestNodeValue){
            ans++;
            latestGreatestNodeValue = root->val;
        }

        findGoodNodes(root->left, latestGreatestNodeValue);
        findGoodNodes(root->right, latestGreatestNodeValue);
    }
public:
    int goodNodes(TreeNode* root) {
        findGoodNodes(root, INT_MIN);
        return ans;
    }
};
