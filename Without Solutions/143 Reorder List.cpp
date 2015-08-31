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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *cur = head, *first = head, *second = head, *nxt = NULL, *prev = NULL;

        while(cur){
            cur = cur->next;
            n++;
        }

        if (n < 3) return;

        for (int i = 0; i < (n + 1) / 2; i++){
            second = second->next;
        }

        while(second){
            nxt = second->next;
            second->next = prev;
            prev = second;
            second = nxt;
        }
        second = prev;

        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                prev = first;
                nxt = first->next;
                first->next = second;
                first = nxt;
            }
            else{
                prev = second;
                nxt = second->next;
                second->next = first;
                second = nxt;
            }
        }

        prev->next = NULL;
    }
};
