/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto root = head;
        int len = 0;
        while(root){
            root = root->next;
            len++;
        }
        n = len - n;
        root = head;

        if (n == 0){
            auto ans = head->next;
            delete head;
            return ans;
        }
        else{
            for (int i = 0; i < n - 1; i++) root = root->next;
            auto tmp = root->next;
            root->next = root->next->next;
            delete tmp;
            return head;
        }
    }
};