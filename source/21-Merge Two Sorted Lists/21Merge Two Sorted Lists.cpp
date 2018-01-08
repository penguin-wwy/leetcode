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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode * head = new ListNode(0);
    	ListNode * ptr = head;
    
    	while (nullptr != l1 || nullptr != l2){
    		ListNode * cur = nullptr;
    		if (nullptr == l1){
    			cur = l2;
    			l2 = l2->next;
    		}
    		else if (nullptr == l2){
    			cur = l1;
    			l1 = l1->next;
    		}
    		else{
    			if (l1->val < l2->val){
    				cur = l1;
    				l1 = l1->next;
    			}
    			else{
    				cur = l2;
    				l2 = l2->next;
    			}
    		}
    		ptr->next = cur;
    		ptr = ptr->next;
    	}
    	return head->next;
    }
};