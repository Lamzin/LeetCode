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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        ListNode* cur = head;
        stack<ListNode*> st;
        
        for (int i = 1; i <= k && cur; i++){
            st.push(cur);
            cur = cur->next;
            if (i < k && cur == NULL) return head;
        }

        ListNode* current = head = st.top();
        st.pop();
        while(!st.empty()){
            current->next = st.top();
            st.pop();
            current = current->next;
        }
        current->next = reverseKGroup(cur, k);
        return head;

    }
};
