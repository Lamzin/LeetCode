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
    vector<int> ans;

    void dfs(TreeNode* root, int height){
        if (root == NULL){
            return;
        }

        if (ans.size() == height){
            ans.push_back(root->val);
        }

        dfs(root->right, height + 1);
        dfs(root->left, height + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        ans.clear();

        dfs(root, 0);

        return ans;
    }
};