/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    struct ListNode *first = head;
    struct ListNode *last = head;
    for(int i = 1; i < m; i++){
    	first = first->next;
    }
    for(int i = 0; i < n; i++){
    	last = last->next;
    }
    struct ListNode *prev = first;
    struct ListNode *pcur = prev->next;
    while(pcur != last)
    {
    	prev->next = pcur->next;
    	pcur->next = first;
    	first = pcur;
    	pcur = prev->next;
    }
    if(1 == m)
        head = first;
    else
        {
            struct ListNode *zero = head;
            while(zero->next != prev)
                zero = zero->next;
            zero->next = first;
        }
    return head;
}