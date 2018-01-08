/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}
/*
设置快、慢指针，相遇即为true
http://articles.leetcode.com/2010/09/detecting-loop-in-singly-linked-list.html
*/
