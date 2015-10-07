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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0, m = 0;
        ListNode *current = NULL;


        for (int i = 0; i < 2; i++){
            current = headA;
            while(current){
                current = current->next;
                n++;
            }

            swap(n, m);
            swap(headA, headB);
        }

        if (n > m){
            swap(n, m);
            swap(headA, headB);
        }

        for (int i = 0; i < m - n; i++){
            headB = headB->next;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }        

        return headA;

    }
};