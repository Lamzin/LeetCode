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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        auto nxt = head->next, nxt_nxt = head->next->next;
        nxt->next = head;
        head->next = swapPairs(nxt_nxt);
        return nxt;
    }
};