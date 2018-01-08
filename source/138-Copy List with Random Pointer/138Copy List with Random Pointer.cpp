/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(nullptr == head)
            return nullptr;
        RandomListNode *cur; 
        RandomListNode *node; 
        // 构造新节点
        for (cur = head; cur; ) {
            node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        for (cur = head; cur; ) {
            if (cur->random != NULL)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        // 分拆两个单链表
        RandomListNode dummy(-1);
        RandomListNode *new_cur = &dummy;
        cur = head;
        while (cur) {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};