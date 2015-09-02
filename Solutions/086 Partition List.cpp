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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;

        ListNode *current = head, *less = NULL, *greater = NULL, *less_start = NULL, *greater_start = NULL;

        while(current){
            if (current->val < x){
                if (!less_start){
                    less_start = current;
                    less = current;
                }
                else{
                    less->next = current;
                    less = current;
                }
            }
            else{
                if (!greater_start){
                    greater_start = current;
                    greater = current;
                }
                else{
                    greater->next = current;
                    greater = current;
                }
            }

            current = current->next;
        }

        if (!less_start){
            greater->next = NULL;
            return greater_start;
        }
        else{
            if (!greater_start){
                less->next = NULL;
                return less_start;
            }            
            less->next = greater_start;
            greater->next = NULL;
            return less_start;
        }
    }
};