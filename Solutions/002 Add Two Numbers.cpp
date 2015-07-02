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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0), *tmp = ans;
        int cur = 0;
        
        while(tmp){
            if (l1) cur += l1->val, l1 = l1->next;
            if (l2) cur += l2->val, l2 = l2->next;
            
            tmp->val = cur % 10;
            cur /= 10;
        
            if (l1 || l2 || cur) tmp->next = new ListNode(0);
            tmp = tmp->next;
        }
        return ans;
    }
};