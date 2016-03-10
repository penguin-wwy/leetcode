class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return -1;
        
        start, end, step = 0, 0, 0
        while end < len(nums) - 1:
            step += 1
            farthest = end
            for i in range(start, end + 1):
                if farthest < nums[i] + i:
                    farthest = nums[i] + i
            start = end + 1
            end = farthest
        
        return step