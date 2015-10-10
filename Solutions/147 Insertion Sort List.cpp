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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode *current = head, *go, *insert, *tmp1, *tmp2, *prev, *previous = NULL;

        while (current){
            insert = prev = NULL;
            go = head;
            while (go != current){
                if (go->val > current->val){
                    insert = prev;
                    prev = go;
                    break;
                }
                prev = go;
                go = go->next;
            }

            if (prev && prev->val > current->val){
                if (insert){
                    tmp1 = insert->next;
                    tmp2 = current->next;

                    insert->next = current;
                    current->next = tmp1;

                    current = tmp2;
                }
                else{
                    tmp1 = head;
                    tmp2 = current->next;

                    head = current;
                    current->next = tmp1;

                    current = tmp2;
                }
                previous->next = current;
            }
            else{
                previous = current;
                current = current->next;
            }

        }

        return head;
    }
};