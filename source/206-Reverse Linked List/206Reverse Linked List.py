# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if None == head or None == head.next:
            return head
        prev = head
        pcur = head.next
        while(pcur):
            prev.next = pcur.next
            pcur.next = head
            head = pcur
            pcur = prev.next
        return head