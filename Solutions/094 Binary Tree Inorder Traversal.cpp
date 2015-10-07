/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> travel;
    void dfs(TreeNode *root){
        if (root == NULL) return;

        dfs(root->left);
        travel.push_back(root->val);
        dfs(root->right);
    }


public:
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return travel;
    }
};