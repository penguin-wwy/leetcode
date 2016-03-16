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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *sortedHead = new ListNode(-1);
        while(head != NULL)
        {
            ListNode *temp = head->next;
            ListNode *cur = sortedHead;
            while(cur->next != NULL && cur->next->val < head->val)
            {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = temp;
        }
        return sortedHead->next;
    }
};