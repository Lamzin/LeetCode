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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        stack<pair<TreeNode*, int>> dfs;
        dfs.push(make_pair(root, 0));

        while(!dfs.empty()){
            if (dfs.top().first == NULL) dfs.pop();
            else if (dfs.top().second == 0){
                dfs.top().second++;
                dfs.push(make_pair(dfs.top().first->left, 0));
            }
            else if (dfs.top().second == 1){
                dfs.top().second++;
                dfs.push(make_pair(dfs.top().first->right, 0));
            }
            else if (dfs.top().second == 2){
                postorder.push_back(dfs.top().first->val);
                dfs.pop();
            }
        }

        return postorder;
    }
};



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// private:
//     vector<int> *postorder;

//     void dfs(TreeNode *root){
//         if (root == NULL) return;
//         dfs(root->left);
//         dfs(root->right);
//         postorder->push_back(root->val);
//     }

// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         postorder = new vector<int>();
//         dfs(root);
//         return *postorder;
//     }
// };