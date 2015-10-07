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
    bool isPalindrome(ListNode* head) {
        ListNode *current = head, *prev = NULL, *next = NULL;
        int len = 0;

        for (len = 0; current; len++) current = current->next;

        current = head;
        for (int i = 0; i < len / 2; i++){
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        if (len % 2) current = current->next;

        while(current){
            if (current->val != prev->val) return false;
            current = current->next;
            prev = prev->next;
        }

        return true;
    }
};