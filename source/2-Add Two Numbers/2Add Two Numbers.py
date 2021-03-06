# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        dum = ListNode(0)
        cur = dum
        car = 0

        while None != l1 or None != l2:
            sum = 0
            if l1 != None:
                sum += l1.val
                l1 = l1.next

            if l2 != None:
                sum += l2.val
                l2 = l2.next

            cur.next = ListNode((sum + car) % 10)
            car = (sum  + car) // 10
            cur = cur.next

        if 1 == car:
            cur.next = ListNode(car)

        return dum.next
        