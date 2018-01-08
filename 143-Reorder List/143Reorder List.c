/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head);
void reorderList(struct ListNode* head) {
     if(NULL == head || NULL == head->next)
 		return ;
	struct ListNode *pcur = head, *fast = head, *slow = head;
	while(fast && fast->next)
	{
		pcur = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if(NULL == fast)
		pcur->next = NULL;
	else {
		slow = slow->next;
		pcur = pcur->next;
		pcur->next = NULL;
	}
	slow = reverseList(slow);
	struct ListNode *prev = head;
	struct ListNode *temp = head;
	while(prev && slow)
	{
		if(temp == prev){
			prev = prev->next;
			temp->next = slow;
			temp = temp->next;
		}
		else if(temp == slow){
			slow = slow->next;
			temp->next = prev;
			temp = temp->next;
		}	
	}
}

 struct ListNode* reverseList(struct ListNode* head) {
    if(NULL == head && NULL == head->next)
		return head;
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