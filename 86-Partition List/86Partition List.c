/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    if(NULL == head)
        return NULL;
    struct ListNode low;
    low.next = NULL;
	struct ListNode big;
	big.next = NULL;
	struct ListNode *left = &low;
	struct ListNode *right = &big;
	for(struct ListNode *cur = head; cur; cur = cur->next)
	{
		if(cur->val < x)
		{
			left->next = cur;
			left = cur;
		}
		else
		{
			right->next = cur;
			right = cur;
		}
	}
	left->next = big.next;
	right->next = NULL;
	
	return low.next;
}