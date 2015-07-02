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
        
        ListNode *ans = NULL, *cur = head, *tmp = NULL;
        
        while(cur != NULL){
            if (cur->next == NULL || cur->val != cur->next->val){
                if (tmp == NULL) tmp = ans = new ListNode(cur->val);
                else{
                    tmp->next = new ListNode(cur->val);
                    tmp = tmp->next;
                }
                cur = cur->next;
            }
            else{
                int prev = cur->val;
                while(cur != NULL && cur->val == prev) cur = cur->next;
            }
        }
        
        return ans;
    }
};