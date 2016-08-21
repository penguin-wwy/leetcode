class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        org = n
        set = [org]
        while 1:
            digit = []
            while n % 10 or n > 9:
                digit.append(n % 10)
                n //= 10
    
            n = 0
            for i in digit:
                n += (i * i)
    
            if n == 1:
                return True
            elif n not in set:
                set.append(n)
            else:
                return False