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
    pair<bool, int> height(TreeNode* root){
        if (root == NULL) 
            return make_pair(true, 0);
        pair<bool, int> l = height(root->left), r = height(root->right);
        if (l.first && r.first && abs(l.second - r.second) < 2)
            return make_pair(true, max(l.second, r.second) + 1);
        else 
            return make_pair(false, 0);
    }

    bool isBalanced(TreeNode* root) {
        pair<int, int> deep = height(root);
        return deep.first;
    }
};