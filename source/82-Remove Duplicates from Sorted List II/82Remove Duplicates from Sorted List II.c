/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(NULL == head)
		return NULL;
	struct ListNode result;
	result.next = NULL;
	struct ListNode *k = &result;
	struct ListNode *p = head;
	int cur = -65535;
	while(p)
	{
		if((NULL == p->next || p->val != p->next->val) && p->val != cur)
		{
			k->next = p;
			k = k->next;
			p = p->next;
		}
		else if((NULL == p->next || p->val == p->next->val) && p->val != cur)
		{
			cur = p->val;
			p = p->next;
		}
		else if(p->val == cur)
			p = p->next;
	}
	k->next = NULL;
	return result.next;
}