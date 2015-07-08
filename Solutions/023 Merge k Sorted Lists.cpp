/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct node{
    ListNode *root;
    int index;

    bool operator < (const node &b) const{
        return root->val > b.root->val;
    }

    node(ListNode *Root, int Index){
        root = Root;
        index = Index;
    }
    node(){
        root = NULL;
        index = 0;
    }
};


class Solution {
protected:


public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        node minNode;
        ListNode *ansHead = NULL, *ansTail = NULL;
        priority_queue <node> prior;

        for (int i = 0; i < lists.size(); i++){
            if (lists[i] != NULL){
                prior.push(node(lists[i], i));
                lists[i] = lists[i]->next;
            }
        }

        while(!prior.empty()){
            minNode = prior.top();
            prior.pop();

            if (ansHead == NULL){
                ansHead = ansTail = minNode.root;
                ansHead->next = NULL;
            }
            else{
                ansTail->next = minNode.root;
                ansTail = ansTail->next;
                ansTail->next = NULL;
            }

            if (lists[minNode.index] != NULL){
                prior.push(node(lists[minNode.index], minNode.index));
                lists[minNode.index] = lists[minNode.index]->next;
            }
        }

        return ansHead;
    }
};