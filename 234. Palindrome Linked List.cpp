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
    bool isPalindrome(ListNode* head) {
        if (NULL == head)
    		return true;
    	vector<int> vec1;
    	
    	ListNode *pCur = head;
    	while (pCur != NULL){
    		vec1.push_back(pCur->val);
    		pCur = pCur->next;
    	}
    	vector<int> vec2(vec1);
    	reverse(vec2.begin(), vec2.end());
    	if (vec1 == vec2)
    		return true;
    	else
    		return false;
    }
};