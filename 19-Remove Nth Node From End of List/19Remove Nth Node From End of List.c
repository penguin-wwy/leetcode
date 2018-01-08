/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(NULL == head)
		return NULL;
	struct ListNode *p = head;
	struct ListNode *q = head;
	for(int i = 0; i < n; i++)
	{
		p = p->next;
	}
	if(NULL == p)
		return head->next;
	while(p->next)
	{
		p = p->next;
		q = q->next;
	}
	q->next = q->next->next;
	return head;
}