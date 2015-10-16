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
    int result = -2147483648;
    int dfs(TreeNode* root){
        if (root == NULL) return 0;
        int l = dfs(root->left), r = dfs(root->right);
        result = max(result, max(max(l + r, 0), max(l, r)) + root->val);

        return root->val + max(0, max(l, r));
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return result;
    }
};