/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* makeBST(ListNode* list, int len){
        if (len == 0){
            return NULL;
        }
        if (len == 1){
            return new TreeNode(list->val);
        }

        int sz = 0;
        auto right = list;

        for (int i = 0; i < len / 2; i++){
            right = right->next;
            sz++;
        }

        TreeNode *ans = new TreeNode(right->val);

        while(right && right->next && right->val == right->next->val){
            right = right->next;
            sz++;
        }

        ans->left = makeBST(list, sz);
        ans->right = makeBST(right->next, len - sz - 1);

        return ans;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        auto tmp = head;
        int len = 0;
        while(tmp){
            tmp = tmp->next;
            len++;
        }

        return makeBST(head, len);
    }
};