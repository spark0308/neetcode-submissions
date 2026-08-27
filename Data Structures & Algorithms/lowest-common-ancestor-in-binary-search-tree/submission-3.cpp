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

    bool findTarget(TreeNode* root, TreeNode* target){
        if(root == nullptr) return false;
        if(root->val == target->val) return true;

        if(findTarget(root->left, target)) return true;
        if(findTarget(root->right, target)) return true;

        return false;
    }

    void printVector(vector<TreeNode*> vec){ for(auto x: vec) cout<<x->val<<" "; }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path = vector<TreeNode*>();
        getPath(root, p, path);

        printVector(path);

        int pSize = path.size();

        for(int i = pSize-1; i>=0; i--){
            if(path[i]->val == q->val) return path[i];
            bool found = false;
            if(i==pSize-1){
                found = findTarget(path[i], q);
            }
            else{
                if(path[i+1] == path[i]->left) found = findTarget(path[i]->right, q);
                else found = findTarget(path[i]->left, q);
            }

            if(found) return path[i];
        }

        return p;

    }
};
