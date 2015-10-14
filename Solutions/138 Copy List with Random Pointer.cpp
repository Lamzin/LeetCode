/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<RandomListNode *, RandomListNode *> un_map;

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        auto it = un_map.find(head);
        if (it != un_map.end())return it->second;
        
        RandomListNode *new_head = new RandomListNode(head->label);
        un_map[head] = new_head;
        new_head->next = copyRandomList(head->next);
        new_head->random = copyRandomList(head->random);
        return new_head;
    }
};