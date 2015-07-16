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
    vector<vector<int>>* path(TreeNode* root, int sum) {
        if (root == NULL){
            return new vector<vector<int>>();
        }
        else if (root->left == NULL && root->right == NULL && sum - root->val == 0){
            return new vector<vector<int>>(1, vector<int>(1, root->val));
        }
        else{
            auto l = path(root->left, sum - root->val);
            auto r = path(root->right, sum - root->val);
            for (int i = 0; i < r->size(); i++){
                l->push_back((*r)[i]);
            }
            for (int i = 0; i < l->size(); i++){
                (*l)[i].push_back(root->val);
            }
            //delete r;
            return l;
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        auto arr = path(root, sum);
        vector<vector<int>> ans;

        for (int i = 0; i < arr->size(); i++){
            ans.push_back(vector<int>());
            for (int j = (*arr)[i].size() - 1; j >=0; j--){
                ans[i].push_back((*arr)[i][j]);
            }
        }

        return ans;
    }

};