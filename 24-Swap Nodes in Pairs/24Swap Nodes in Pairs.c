/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if(NULL == head || NULL == head->next)
		return head;
	struct ListNode node;
	node.next = head;
	struct ListNode *dum = &node;
	struct ListNode *cur = head;
	struct ListNode *next = cur->next;
	for(; next; dum = cur, cur = cur->next, next = cur ? cur->next : NULL)
	{
		dum->next = next;
		cur->next = next->next;
		next->next = cur;
	}
	return node.next;
}