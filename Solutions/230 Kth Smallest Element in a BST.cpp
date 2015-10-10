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
    int _ans;
    int count(TreeNode* root, int k){
        if (root == NULL) return 0;
        
        int cnt = count(root->left, k);
        if (cnt >= k) return 1 << 20;

        if (++cnt == k){
            _ans = root->val;
            return 1 << 20;
        }

        cnt += count(root->right, k - cnt);
        return cnt;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        _ans = 0;

        count(root, k);

        return _ans;
    }
};