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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *ans = new ListNode(head->val), *tmp = ans;
        
        while(head != NULL){
            if (tmp->val != head->val){
                tmp->next = new ListNode(head->val);
                tmp = tmp->next;
            }
            
            head = head->next;
        }
        
        return ans;
    }
};