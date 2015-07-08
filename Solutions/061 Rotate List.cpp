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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) return head;

        auto cur = head, last = head, ans = head;
        int n = 0;

        while(cur){
            n++;
            last = cur;
            cur = cur->next;
        }
        k %= n;
        if (k == 0) return head;
        k = n - k;

        cur = head;
        for (int i = 0; i < k - 1; i++)
            cur = cur->next;

        ans = cur->next;
        cur->next = NULL;
        last->next = head;

        return ans;
    }
};