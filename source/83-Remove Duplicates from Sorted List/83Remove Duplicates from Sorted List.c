/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode result;
    result.next = NULL;
    struct ListNode *k = &result;
    struct ListNode *p = head;
    while(p)
    {
        if(NULL == p->next || p->val != p->next->val)
        {
            k->next = p;
            k = k->next;
        }
        p = p->next;
    }
    return result.next;
}