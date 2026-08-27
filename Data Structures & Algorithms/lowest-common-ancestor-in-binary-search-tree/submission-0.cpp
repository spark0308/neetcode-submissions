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
private:
    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){
        if(root == nullptr) return false;

        path.push_back(root);
        if(root->val == target->val) return true;

        if(getPath(root->left, target, path)) return true;

        if(getPath(root->right, target, path)) return true;

        path.pop_back();

        return false;
    }

    void printVector(vector<TreeNode*> vec){ for(auto x: vec) cout<<x->val<<" "; }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath = vector<TreeNode*>();
        vector<TreeNode*> qPath = vector<TreeNode*>();
        getPath(root, p, pPath);
        getPath(root, q, qPath);

        int pSize = pPath.size();
        int qSize = qPath.size();
        TreeNode* ans;

        for(int i = 0; i<min(pSize, qSize); i++){
            if(pPath[i]->val == qPath[i]->val) ans = pPath[i];
            else break;
        }

        return ans;

    }
};
