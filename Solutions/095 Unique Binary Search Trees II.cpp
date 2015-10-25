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
    unordered_map<long long, vector<TreeNode*>> un_map;

    vector<TreeNode*> generateTrees(long long l, long long r){
        if (r < l) return vector<TreeNode*>(1, NULL);

        auto it = un_map.find(l * (1L << 32) + r);
        if (it != un_map.end()) return it->second;

        vector<TreeNode*> result;
        if (l == r){
            result.push_back(new TreeNode(l));
            return un_map[l * (1L << 32) + r] = result;  
        }


        for (int i = l; i <= r; i++){
            auto left_arr = generateTrees(l, i - 1);
            auto right_arr = generateTrees(i + 1, r);

            for (auto it_left : left_arr)
                for (auto it_right : right_arr){
                    TreeNode *cur = new TreeNode(i);
                    cur->left = it_left;
                    cur->right = it_right;
                    result.push_back(cur);
                }
        }

        return un_map[l * (1L << 32) + r] = result;
    }


public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(1, NULL);
        return generateTrees(1, n);
    }
};