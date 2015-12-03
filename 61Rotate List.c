/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(NULL == head)
		return NULL;
	int len = 1;
	struct ListNode *pTail = head;
	while(pTail->next)
	{
		len++;
		pTail = pTail->next;
	}
	pTail->next = head;
	k = k % len;
	for(int i = 1; i < len - k; i++)
	{
		head = head->next;
	}
	pTail = head;
	head = pTail->next;
	pTail->next = NULL;
	return head;
}