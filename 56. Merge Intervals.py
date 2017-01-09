# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) <= 1:
            return intervals
        res = []
        stack = []
        tmp = sorted(intervals, key = lambda interval : interval.start)
        stack.append(tmp[0].start)
        tmp_end = tmp[0].end
        for i in range(1, len(tmp)):
            if tmp[i].start > tmp_end:
                res.append(Interval(stack[0], tmp_end))
                stack = []
                stack.append(tmp[i].start)
                tmp_end = tmp[i].end
            else:
                if tmp[i].end <= tmp_end:
                    pass
                else:
                    stack.append(tmp[i].start)
                    tmp_end = tmp[i].end

            if i == len(tmp) - 1:
                if len(stack) != 0:
                    res.append(Interval(stack[0], tmp_end))
        if tmp[-1].start > res[-1].end:
            res.append(tmp[-1])
        return res