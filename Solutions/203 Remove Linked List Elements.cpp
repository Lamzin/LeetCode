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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans = NULL, *cur = head, *tail = NULL;
        
        while(cur){
            if (cur->val != val){
                if (ans == NULL) ans = tail = new ListNode(cur->val);
                else{
                    tail->next = new ListNode(cur->val);
                    tail = tail->next;
                }
            }
            cur = cur->next;
        }
        
        return ans;
    }
};