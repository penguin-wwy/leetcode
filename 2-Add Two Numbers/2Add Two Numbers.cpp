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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int value = 0;
        int ai, bi;
        ListNode dum(-1);
        ListNode *prev = &dum;
        for(ListNode *pa = l1, *pb = l2; 
            nullptr != pa || nullptr != pb;
            pa = (nullptr == pa ? nullptr : pa->next), pb = (nullptr == pb ? nullptr : pb->next), prev = prev-> next)
        {
            ai = (nullptr == pa ? 0 : pa->val);
            bi = (nullptr == pb ? 0 : pb->val);
            value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value);
        }
        if(0 < carry)
        {
            prev->next = new ListNode(carry);
        }
        return dum.next;
    }
};