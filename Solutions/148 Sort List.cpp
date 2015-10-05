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
    ListNode* sortList(ListNode* head) {

            
        ListNode *current = head, *tail = NULL;
        ListNode *current1 = NULL, *current2 = NULL;
        int n = 0, len1, len2;

        while(current){
            n++;
            current = current->next;
        }

        for(int i = 1; i < n; i *= 2){
            current = head;
            head = NULL;
            tail = NULL;

            for (int j = 0; j < n - i; j += 2 * i){
                len1 = i;
                len2 = min(n - j - i, i);

                current1 = current;
                for (int g = 0; g < i; g++){
                    current = current->next;
                }
                current2 = current;

                while(len1 + len2){
                    if (len2 > 0 && (len1 == 0 || current1->val > current2->val)){
                        if (head == NULL) head = tail = current2;
                        else tail->next = current2;
                        tail = current2;
                        current2 = current2->next;
                        len2--;
                    }
                    else{
                        if (head == NULL) head = tail = current1;
                        else tail->next = current1;
                        tail = current1;
                        current1 = current1->next;
                        len1--;
                    }
                }

                tail->next = NULL;

            }

        }

        return head;
    }
};