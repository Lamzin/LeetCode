class Solution {
protected:
    bool isTerminal(int index, int height, TreeNode* root){
        // if (root == NULL) return false;
        // if (height == 0 && root->left == NULL && root->right == NULL) return true;
        // return ((1 << height - 1) & index) ?
        //     isTerminal(index, height - 1, root->right) :
        //     isTerminal(index, height - 1, root->left);

        for (int h = height; h > 0; h--){
            if (root == NULL) return false;
            if ((1 << h - 1) & index)
                root = root->right;
            else
                root = root->left;
        }
        return root != NULL;
    }

public:
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;

        auto left = root, right = root;
        int leftHeight = 0, rightHeight = 0;

        while (left){
            left = left->left;
            leftHeight++;
        }
        while (right){
            right = right->right;
            rightHeight++;
        }

        int POW_HEIGHT = (1 << (leftHeight - 1));
        if (leftHeight == rightHeight){
            return POW_HEIGHT * 2 - 1;
        }

        int l = 0, r = POW_HEIGHT - 1, m = 0;
        while (l < r){
            m = l + (r - l) / 2;
            if (isTerminal(m, leftHeight - 1, root))
                l = m + 1;
            else
                r = m;
        }

        return (POW_HEIGHT - 1) + r;
    }
};