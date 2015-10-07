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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *prev, *current = head, *part_before, *next, *begin;
        prev = part_before = next = begin = NULL;

        for(int i = 1; current != NULL; i++){
            next = current->next;

            if (i < m){
                part_before = current;
            }
            else if (i == m){
                begin = current;
                part_before = prev;
            }
            else if (i <= n){
                current->next = prev;
            }
            else{
                break;
            }

            prev = current;
            current = next;
        }

        begin->next = current;
        if (part_before) part_before->next = prev;
        else head = prev;

        return head;
    }
};