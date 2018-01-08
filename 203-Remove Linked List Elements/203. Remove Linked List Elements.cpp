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
    ListNode* removeElements(ListNode* head, int val) {
        if (NULL == head)
    		return NULL;
    	ListNode ListHead(-1);
    	ListHead.next = head;
    
    	ListNode *pCur = NULL;
    	ListNode *prev = NULL;
    
    	pCur = head;
    	prev = &ListHead;
    	while (pCur != NULL)
    	{
    		if (pCur->val == val){
    			ListNode *p = pCur->next;
    			prev->next = p;
    			free(pCur);
    			pCur = p;
    		}
    		else{
    			prev = pCur;
    			pCur = pCur->next;
    		}
    	}
    	return ListHead.next;
    }
};