/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//第一段VS2013编译通过，但是leetcode显示runtime error
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
	if (NULL == head || NULL == head->next)
		return head;
	if (1 == k)
		return head;
	int len = 1;
	struct ListNode *pcur = head;
	while (pcur->next)
	{
		len++;
		pcur = pcur->next;
	}
	int n = len / k + 1;
	struct ListNode **group = (struct ListNode **)malloc(n * 4);
	pcur = head;
	group[0] = head;
	for (int i = 1; i < n; i++)
	{
		for (int m = 0; m < k; m++)
			pcur = pcur->next;
		group[i] = pcur;
	}
	struct ListNode **prev = (struct ListNode **)malloc((n - 1) * 4);
	for (int i = 0; i < n - 1; i++)
	{
		prev[i] = group[i];
		pcur = prev[i]->next;
		for (int m = 1; m < k; m++)
		{
			prev[i]->next = pcur->next;
			pcur->next = group[i];
			group[i] = pcur;
			pcur = prev[i]->next;
		}
	}
	for (int i = 0; i < n - 1; i++)
		prev[i]->next = group[i + 1];
	head = group[0];
	free(group);
	free(prev);
	return head;
}

//Accept
struct ListNode* reverseKGroup2(struct ListNode* head, int k)
{
	if (NULL == head || NULL == head->next)
		return head;
	struct ListNode *next_group = head;
	for (int i = 0; i < k; ++i) {
		if (next_group)
			next_group = next_group->next;
		else
			return head;
	}
	struct ListNode *new_next_group = reverseKGroup(next_group, k);
	struct ListNode *prev = NULL, *cur = head, *next;
	while (cur != next_group) {
		next = cur->next;
		cur->next = prev ? prev : new_next_group;
		prev = cur;
		cur = next;
	}
	return prev;
}