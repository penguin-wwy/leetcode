# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(-1)
        p = head
        while None != l1 or None != l2:
            cur = None
            if None == l1:
                cur = l2
                l2 = l2.next
            elif None == l2:
                cur = l1
                l1 = l1.next
            else:
                if l1.val < l2.val:
                    cur = l1
                    l1= l1.next
                else:
                    cur = l2
                    l2 = l2.next
            p.next = cur
            p = p.next
        return head.next