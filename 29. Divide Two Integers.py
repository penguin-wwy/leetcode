class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == 0 or divisor == 0:
            return 0
        flag = 1
        res = 0
        tmp_dividend = dividend
        tmp_divisor = divisor
        more = 0
        if dividend < 0:
            flag *= -1
            tmp_dividend = -1 * dividend
        if divisor < 0:
            flag *= -1
            tmp_divisor = -1 * divisor
    
        if tmp_dividend < tmp_divisor:
            return 0
        elif tmp_dividend == tmp_divisor:
            return flag
    
        while tmp_dividend > tmp_divisor:
            while tmp_dividend > (tmp_divisor << more):
                more += 1
            if tmp_dividend == (tmp_divisor << more):
                res += 1 << more
                break
            res += 1 << (more - 1)
            tmp_dividend -= (tmp_divisor << (more - 1))
            more = 0
        if tmp_dividend == tmp_divisor:
            res += 1
        return flag * res