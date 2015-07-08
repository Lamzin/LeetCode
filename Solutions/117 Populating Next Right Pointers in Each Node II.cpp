/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *current = root, *left = NULL, *right = NULL;

        while(current != NULL){
            if (current->left != NULL){
                if (left == NULL){
                    left = right = current->left;
                }
                else{
                    right->next = current->left;
                    right = right->next;
                }
            }
            if (current->right != NULL){
                if (left == NULL){
                    left = right = current->right;
                }
                else{
                    right->next = current->right;
                    right = right->next;
                }
            }

            if (current->next == NULL){
                current = left;
                left = right = NULL;
            }
            else{
                current = current->next;
            }
        }
    }
};