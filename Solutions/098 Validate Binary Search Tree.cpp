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
    bool __isValidBST(TreeNode* root, long long ll, long long rr) {
        
     if (root == NULL){
            return true;
        }
        else{
            if (root->val <= ll || root->val >= rr) return false;

            bool l = true, r = true;

            if (root->left != NULL && !__isValidBST(root->left, ll, root->val)){
                l = false;
            }

            if (root->right != NULL && !__isValidBST(root->right, root->val, rr)){
                r = false;
            }

            return l && r;
        }

    }

public:
    bool isValidBST(TreeNode* root) {
        return __isValidBST(root, -10000000000000000000000000, 10000000000000000000000000);   
    }

};