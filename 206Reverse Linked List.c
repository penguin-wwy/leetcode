/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL)
		return NULL;
    struct ListNode *prev = head;
	struct ListNode *pcur = head->next;
	while(pcur)
	{
		prev->next = pcur->next;
		pcur->next = head;
		head = pcur;
		pcur = prev->next;
	}
	return head;
}