/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (NULL == head)
    		return NULL;
    	else if(NULL == head->next)
    	    return head;
    	ListNode *first = head, *second = head->next;
    	ListNode *pCur = NULL, *pNext = NULL;
    
    	pCur = head;
    	pNext = pCur->next;
    	while (pNext->next != NULL)
    	{
    		pCur->next = pNext->next;
    		pCur = pNext;
    		pNext = pCur->next;
    	}
    	pCur->next = NULL;
    
    	pCur = first;
    	while (pCur->next != NULL){
    		pCur = pCur->next;
    	}
    	pCur->next = second;
    	return head;
    }
};