/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
protected:
        vector<TreeLinkNode *> left;

        void dfs(TreeLinkNode *root, int height){
            if (root == NULL) return;
            if (root != left[height]){
                left[height]->next = root;
                left[height] = root;
            }
            dfs(root->left, height + 1);
            dfs(root->right, height + 1);
        }

public:
    void connect(TreeLinkNode *root) {
        auto tmp = root;

        while(tmp){
            left.push_back(tmp);
            tmp = tmp->left;
        }

        dfs(root, 0);
    }
};