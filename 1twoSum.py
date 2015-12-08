class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for index in range(0, len(nums)):
            num = nums[index]
            if num in dict:
                return [dict[num] + 1, index + 1]
            else:
                dict[target - num] = index