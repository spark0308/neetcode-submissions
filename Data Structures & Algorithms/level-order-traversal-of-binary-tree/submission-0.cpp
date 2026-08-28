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
    queue<pair<TreeNode*, int>> q = queue<pair<TreeNode*, int>>();

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) return ans;

        q.push({root, 1});

        while(!q.empty()){
            TreeNode* front = q.front().first;
            int level = q.front().second;

            if(ans.size() != level) ans.push_back({front->val});
            else ans[level-1].push_back(front->val);

            if(front->left != nullptr) q.push({front->left, level + 1});
            if(front->right != nullptr) q.push({front->right, level + 1});

            q.pop();
        }

        return ans;
    }
};
