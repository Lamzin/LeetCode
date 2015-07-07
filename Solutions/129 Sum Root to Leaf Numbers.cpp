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
protected:
    int ans;
    void dfs(TreeNode *root, int value){
        if (root == NULL) return;
        else if (root->left == NULL && root->right == NULL){
            ans += value * 10 + root->val;
        }
        else{
            dfs(root->left, value * 10 + root->val);
            dfs(root->right, value * 10 + root->val);
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};