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
    vector<string> paths;

    void dfs(TreeNode* root, string current){
        current += to_string(root->val);
        if (!root->left && !root->right) paths.push_back(current);
        else{
            current += "->";
            if (root->left) dfs(root->left, current);
            if (root->right) dfs(root->right, current);
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root != NULL) dfs(root, string());
        return paths;
    }
};