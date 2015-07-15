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
    vector<int> *vect;
    TreeNode* makeBST(int l, int r){
        if (l > r){
            return NULL;
        }
        if (l == r){
            return new TreeNode((*vect)[l]);    
        }
        int m = (l + r) / 2;
        TreeNode *cur = new TreeNode((*vect)[m]);
        auto it = upper_bound((*vect).begin(), (*vect).end(), (*vect)[m]);

        cur->left = makeBST(l, it - (*vect).begin() - 2);
        cur->right = makeBST(it - (*vect).begin(), r);
        
        return cur;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        vect = &nums;

        return makeBST(0, nums.size() - 1);
    }
};