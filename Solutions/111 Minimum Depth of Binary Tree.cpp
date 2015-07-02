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
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 1000000;
        if (root->left != NULL) depth = min(depth, minDepth(root->left) + 1);
        if (root->right != NULL) depth = min(depth, minDepth(root->right) + 1);
        if (depth == 1000000) depth = 1;
        return depth;
    }
};