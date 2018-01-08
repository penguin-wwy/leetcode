/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head, *slow = head;
 	while(fast && fast->next)
 	{
	 	fast = fast->next->next;
	 	slow = slow->next;
	 	if(fast == slow)
	 	{
	 		struct ListNode *slow2 = head;
	 		while(slow != slow2)
	 		{
		 		slow = slow->next;
		 		slow2 = slow2->next;
		 	}
		 	return slow2;
	 	}
	 }
	 return NULL;
}