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
    vector<TreeNode*> order;
    vector<int> level;
    unordered_map<TreeNode*, int> index;

    void dfs(TreeNode *root, int lvl){
        if (root == NULL) return;

        if (index.find(root) == index.end()) index[root] = order.size();
        order.push_back(root);
        level.push_back(lvl);
        
        if (root->left){
            dfs(root->left, lvl + 1);
            order.push_back(root);
            level.push_back(lvl);
        }

        if (root->right){
            dfs(root->right, lvl + 1);
            order.push_back(root);
            level.push_back(lvl);
        }

    }


public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, 0);

        int level_min = 1 << 30;
        TreeNode *LCA = NULL;
        for (int i = min(index[p], index[q]); i <= max(index[p], index[q]); i++){
            if (level[i] < level_min){
                level_min = level[i];
                LCA = order[i];
            }
        }

        return LCA; 
    }
};